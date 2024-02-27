
def read_ppm(filename):
    """
    Reads a PPM file and returns the image data along with its dimensions.

    Parameters:
    - filename: str, the name of the PPM file to read.

    Returns:
    - dimensions: tuple, the dimensions of the image (width, height).
    - maxval: int, the maximum color value.
    - data: list or numpy array, the image data.
    """
    with open(filename, 'rb') as f:
        # Read the magic number to determine the format (P3 or P6)
        format = f.readline().strip()
        
        # Read next line and skip comments
        line = f.readline().strip()
        while line.startswith(b'#'):
            line = f.readline().strip()
        
        # Read the image dimensions
        dimensions = tuple(map(int, line.split()))
        
        # Read the maximum color value
        maxval = int(f.readline().strip())
        
        # Initialize a list to hold the image data
        data = []
        
        if format == b'P3':
            # ASCII format, read and convert each value
            for line in f:
                pixels = line.strip().split()
                for pixel in pixels:
                    data.append(int(pixel))
        elif format == b'P6':
            # Binary format, read the binary data directly
            data = list(f.read())
        else:
            raise ValueError("Unsupported PPM format")

        return dimensions, maxval, data




