from argparse import ArgumentParser
from tensorflow import keras
import numpy as np
import cv2
import os

parser = ArgumentParser()
parser.add_argument('--image_dir', type=str, help='Directory where images are kept.')
parser.add_argument('--output_dir', type=str, help='Directory where to output high res images.')

def main():
    args = parser.parse_args()
    image_paths = [os.path.join(args.image_dir, x) for x in os.listdir(args.image_dir)]
    model = keras.models.load_model('models/generator.h5', compile=False)
    inputs = keras.Input((None, None, 3))
    output = model(inputs)
    model = keras.models.Model(inputs, output)
    for image_path in image_paths:
        low_res = cv2.imread(image_path, 1)
        low_res = cv2.cvtColor(low_res, cv2.COLOR_BGR2RGB)
        low_res = low_res / 255.0
        sr = model.predict(np.expand_dims(low_res, axis=0))[0]
        sr = (((sr + 1) / 2.) * 255).astype(np.uint8)
        sr = cv2.cvtColor(sr, cv2.COLOR_RGB2BGR)
        cv2.imwrite(os.path.join(args.output_dir, os.path.basename(image_path)), sr)

if __name__ == '__main__':
    main()
