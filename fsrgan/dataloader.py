
import tensorflow as tf
import os

from tensorflow.python.ops import array_ops, math_ops

# Load images from image dir, rescale them to obtain low res
class DataLoader(object):
    def __init__(self, image_dir, hr_image_size):
        self.image_paths = [os.path.join(image_dir, x) for x in os.listdir(image_dir)]
        self.image_size = hr_image_size

    def _parse_image(self, image_path):
        image = tf.io.read_file(image_path)
        image = tf.image.decode_jpeg(image, channels=3)
        image = tf.image.convert_image_dtype(image, tf.float32)
        if tf.keras.backend.image_data_format() == 'channels_last':
            shape = array_ops.shape(image)[:2]
        else:
            shape = array_ops.shape(image)[1:]
        cond = math_ops.reduce_all(shape >= tf.constant(self.image_size))
        image = tf.cond(cond, lambda: tf.identity(image),
                        lambda: tf.image.resize(image, [self.image_size, self.image_size]))

        return image

    def _random_crop(self, image):
        image = tf.image.random_crop(image, [self.image_size, self.image_size, 3])
        return image

    def _high_low_res_pairs(self, high_res):
        low_res = tf.image.resize(high_res, 
                                  [self.image_size // 4, self.image_size // 4], 
                                  method='bicubic')
        return low_res, high_res

    def _rescale(self, low_res, high_res):
        high_res = high_res * 2.0 - 1.0
        return low_res, high_res

    def dataset(self, batch_size, threads=4):
        dataset = tf.data.Dataset.from_tensor_slices(self.image_paths)
        dataset = dataset.map(self._parse_image, num_parallel_calls=tf.data.experimental.AUTOTUNE)
        dataset = dataset.map(self._random_crop, num_parallel_calls=tf.data.experimental.AUTOTUNE)
        dataset = dataset.map(self._high_low_res_pairs, num_parallel_calls=tf.data.experimental.AUTOTUNE)
        dataset = dataset.map(self._rescale, num_parallel_calls=tf.data.experimental.AUTOTUNE)
        dataset = dataset.shuffle(30).batch(batch_size, drop_remainder=True).prefetch(tf.data.experimental.AUTOTUNE)
        return dataset
