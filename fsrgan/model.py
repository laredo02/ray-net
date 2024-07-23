from tensorflow import keras
import tensorflow as tf


class FastSRGAN(object):


    def __init__(self, args):
        self.hr_height = args.hr_size
        self.hr_width = args.hr_size
        self.lr_height = self.hr_height // 4  # Low resolution height
        self.lr_width = self.hr_width // 4  # Low resolution width
        self.lr_shape = (self.lr_height, self.lr_width, 3)
        self.hr_shape = (self.hr_height, self.hr_width, 3)
        self.iterations = 0
        self.n_residual_blocks = 6

        self.gen_schedule = keras.optimizers.schedules.ExponentialDecay(
            args.lr,
            decay_steps=100000,
            decay_rate=0.1,
            staircase=True
        )
        self.disc_schedule = keras.optimizers.schedules.ExponentialDecay(
            args.lr * 5,  # TTUR - Two Time Scale Updates
            decay_steps=100000,
            decay_rate=0.1,
            staircase=True
        )

        self.gen_optimizer = keras.optimizers.Adam(learning_rate=self.gen_schedule)
        self.disc_optimizer = keras.optimizers.Adam(learning_rate=self.disc_schedule)

        self.vgg = self.build_vgg()
        self.vgg.trainable = False

        patch = int(self.hr_height / 2 ** 4)
        self.disc_patch = (patch, patch, 1)
        self.gf = 32
        self.df = 32

        self.discriminator = self.build_discriminator()
        self.generator = self.build_generator()

    @tf.function
    def content_loss(self, hr, sr):
        sr = keras.applications.vgg19.preprocess_input(((sr + 1.0) * 255) / 2.0)
        hr = keras.applications.vgg19.preprocess_input(((hr + 1.0) * 255) / 2.0)
        sr_features = self.vgg(sr) / 12.75
        hr_features = self.vgg(hr) / 12.75
        return tf.keras.losses.MeanSquaredError()(hr_features, sr_features)

    def build_vgg(self):
        vgg = keras.applications.VGG19(weights="imagenet", input_shape=self.hr_shape, include_top=False)
        vgg.trainable = False
        for layer in vgg.layers:
            layer.trainable = False
        model = keras.models.Model(inputs=vgg.input, outputs=vgg.get_layer("block5_conv4").output)
        return model

    def build_generator(self):

        def _make_divisible(v, divisor, min_value=None):
                if min_value is None:
                    min_value = divisor
                new_v = max(min_value, int(v + divisor / 2) // divisor * divisor)
                if new_v < 0.9 * v:
                    new_v += divisor
                return new_v

        def residual_block(inputs, filters, block_id, expansion=6, stride=1, alpha=1.0):
            channel_axis = 1 if keras.backend.image_data_format() == 'channels_first' else -1
            in_channels = keras.backend.int_shape(inputs)[channel_axis]
            pointwise_conv_filters = int(filters * alpha)
            pointwise_filters = _make_divisible(pointwise_conv_filters, 8)
            x = inputs
            prefix = 'block_{}_'.format(block_id)
            if block_id:
                x = keras.layers.Conv2D(expansion * in_channels,
                                        kernel_size=1,
                                        padding='same',
                                        use_bias=True,
                                        activation=None,
                                        name=prefix + 'expand')(x)
                x = keras.layers.BatchNormalization(axis=channel_axis,
                                                    epsilon=1e-3,
                                                    momentum=0.999,
                                                    name=prefix + 'expand_BN')(x)
                x = keras.layers.Activation('relu', name=prefix + 'expand_relu')(x)
            else:
                prefix = 'expanded_conv_'
            x = keras.layers.DepthwiseConv2D(kernel_size=3,
                                             strides=stride,
                                             activation=None,
                                             use_bias=True,
                                             padding='same' if stride == 1 else 'valid',
                                             name=prefix + 'depthwise')(x)
            x = keras.layers.BatchNormalization(axis=channel_axis,
                                                epsilon=1e-3,
                                                momentum=0.999,
                                                name=prefix + 'depthwise_BN')(x)

            x = keras.layers.Activation('relu', name=prefix + 'depthwise_relu')(x)
            x = keras.layers.Conv2D(pointwise_filters,
                                    kernel_size=1,
                                    padding='same',
                                    use_bias=True,
                                    activation=None,
                                    name=prefix + 'project')(x)
            x = keras.layers.BatchNormalization(axis=channel_axis,
                                                epsilon=1e-3,
                                                momentum=0.999,
                                                name=prefix + 'project_BN')(x)

            if in_channels == pointwise_filters and stride == 1:
                return keras.layers.Add(name=prefix + 'add')([inputs, x])
            return x

        def deconv2d(layer_input):
            u = keras.layers.UpSampling2D(size=2, interpolation='bilinear')(layer_input)
            u = keras.layers.Conv2D(self.gf, kernel_size=3, strides=1, padding='same')(u)
            u = keras.layers.PReLU(shared_axes=[1, 2])(u)
            return u

        img_lr = keras.Input(shape=self.lr_shape)

        c1 = keras.layers.Conv2D(self.gf, kernel_size=3, strides=1, padding='same')(img_lr)
        c1 = keras.layers.BatchNormalization()(c1)
        c1 = keras.layers.PReLU(shared_axes=[1, 2])(c1)

        r = residual_block(c1, self.gf, 0)
        for idx in range(1, self.n_residual_blocks):
            r = residual_block(r, self.gf, idx)

        c2 = keras.layers.Conv2D(self.gf, kernel_size=3, strides=1, padding='same')(r)
        c2 = keras.layers.BatchNormalization()(c2)
        c2 = keras.layers.Add()([c2, c1])

        u1 = deconv2d(c2)
        u2 = deconv2d(u1)
        gen_hr = keras.layers.Conv2D(3, kernel_size=3, strides=1, padding='same', activation='tanh')(u2)

        return keras.models.Model(img_lr, gen_hr)

    def build_discriminator(self):
        def d_block(layer_input, filters, strides=1, bn=True):
            d = keras.layers.Conv2D(filters, kernel_size=3, strides=strides, padding='same')(layer_input)
            if bn:
                d = keras.layers.BatchNormalization(momentum=0.8)(d)
            d = keras.layers.LeakyReLU(alpha=0.2)(d)
            return d

        d0 = keras.layers.Input(shape=self.hr_shape)
        d1 = d_block(d0, self.df, bn=False)
        d2 = d_block(d1, self.df, strides=2)
        d3 = d_block(d2, self.df)
        d4 = d_block(d3, self.df, strides=2)
        d5 = d_block(d4, self.df * 2)
        d6 = d_block(d5, self.df * 2, strides=2)
        d7 = d_block(d6, self.df * 2)
        d8 = d_block(d7, self.df * 2, strides=2)
        validity = keras.layers.Conv2D(1, kernel_size=1, strides=1, activation='sigmoid', padding='same')(d8)
        return keras.models.Model(d0, validity)




