from argparse import ArgumentParser
from dataloader import DataLoader
from model import FastSRGAN
import tensorflow as tf
import os

parser = ArgumentParser()
parser.add_argument('--image_dir', type=str, help='Path to high resolution image directory.')
parser.add_argument('--batch_size', default=8, type=int, help='Batch size for training.')
parser.add_argument('--epochs', default=1, type=int, help='Number of epochs for training')
parser.add_argument('--hr_size', default=384, type=int, help='Low resolution input size.')
parser.add_argument('--lr', default=1e-4, type=float, help='Learning rate for optimizers.')
parser.add_argument('--save_iter', default=200, type=int,
                    help='The number of iterations to save the tensorboard summaries and models.')

@tf.function
def pretrain_step(model, x, y):
    with tf.GradientTape() as tape:
        fake_hr = model.generator(x)
        loss_mse = tf.keras.losses.MeanSquaredError()(y, fake_hr)

    grads = tape.gradient(loss_mse, model.generator.trainable_variables)
    model.gen_optimizer.apply_gradients(zip(grads, model.generator.trainable_variables))

    return loss_mse


def pretrain_generator(model, dataset, writer):
    with writer.as_default():
        iteration = 0
        for _ in range(1):
            for x, y in dataset:
                loss = pretrain_step(model, x, y)
                if iteration % 20 == 0:
                    tf.summary.scalar('MSE Loss', loss, step=tf.cast(iteration, tf.int64))
                    writer.flush()
                iteration += 1


@tf.function
def train_step(model, x, y):
    valid = tf.ones((x.shape[0],) + model.disc_patch)
    fake = tf.zeros((x.shape[0],) + model.disc_patch)

    with tf.GradientTape() as gen_tape, tf.GradientTape() as disc_tape:
        fake_hr = model.generator(x)
        valid_prediction = model.discriminator(y)
        fake_prediction = model.discriminator(fake_hr)
        content_loss = model.content_loss(y, fake_hr)
        adv_loss = 1e-3 * tf.keras.losses.BinaryCrossentropy()(valid, fake_prediction)
        mse_loss = tf.keras.losses.MeanSquaredError()(y, fake_hr)
        perceptual_loss = content_loss + adv_loss + mse_loss
        valid_loss = tf.keras.losses.BinaryCrossentropy()(valid, valid_prediction)
        fake_loss = tf.keras.losses.BinaryCrossentropy()(fake, fake_prediction)
        d_loss = tf.add(valid_loss, fake_loss)
    gen_grads = gen_tape.gradient(perceptual_loss, model.generator.trainable_variables)
    model.gen_optimizer.apply_gradients(zip(gen_grads, model.generator.trainable_variables))
    disc_grads = disc_tape.gradient(d_loss, model.discriminator.trainable_variables)
    model.disc_optimizer.apply_gradients(zip(disc_grads, model.discriminator.trainable_variables))

    return d_loss, adv_loss, content_loss, mse_loss


def train(model, dataset, log_iter, writer):
    with writer.as_default():
        for x, y in dataset:
            disc_loss, adv_loss, content_loss, mse_loss = train_step(model, x, y)
            if model.iterations % log_iter == 0:
                tf.summary.scalar('Adversarial Loss', adv_loss, step=model.iterations)
                tf.summary.scalar('Content Loss', content_loss, step=model.iterations)
                tf.summary.scalar('MSE Loss', mse_loss, step=model.iterations)
                tf.summary.scalar('Discriminator Loss', disc_loss, step=model.iterations)
                tf.summary.image('Low Res', tf.cast(255 * x, tf.uint8), step=model.iterations)
                tf.summary.image('High Res', tf.cast(255 * (y + 1.0) / 2.0, tf.uint8), step=model.iterations)
                tf.summary.image('Generated', tf.cast(255 * (model.generator.predict(x) + 1.0) / 2.0, tf.uint8),
                                 step=model.iterations)
                model.generator.save('models/generator.h5')
                model.discriminator.save('models/discriminator.h5')
                writer.flush()
            model.iterations += 1


def main():
    args = parser.parse_args()
    if not os.path.exists('models'):
        os.makedirs('models')
    ds = DataLoader(args.image_dir, args.hr_size).dataset(args.batch_size)
    gan = FastSRGAN(args)
    pretrain_summary_writer = tf.summary.create_file_writer('logs/pretrain')
    pretrain_generator(gan, ds, pretrain_summary_writer)
    train_summary_writer = tf.summary.create_file_writer('logs/train')
    for _ in range(args.epochs):
        train(gan, ds, args.save_iter, train_summary_writer)


if __name__ == '__main__':
    main()
