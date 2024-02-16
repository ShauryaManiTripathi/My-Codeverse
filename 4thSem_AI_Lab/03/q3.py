import numpy as np
import pandas as pd
from PIL import Image

# Load and convert an image to grayscale
image_data = Image.open('sample_image.png').convert('L')

# Convert image to a NumPy array
image_matrix = np.array(image_data)

# Create a DataFrame from the image matrix
image_df = pd.DataFrame(image_matrix)
image_df.to_csv('image_data.csv', index=False, header=False)

# Read the CSV file back into a DataFrame, skipping the footer
read_df = pd.read_csv('image_data.csv', skipfooter=1, engine='python')
read_df = read_df[read_df.columns[:-1]]
