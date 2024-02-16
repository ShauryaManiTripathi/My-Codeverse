import numpy as np

data_matrix = np.array([[11, 22, 33],
                       [44, 55, 66],
                       [77, 88, 99]])

selected_column = data_matrix[:, 1]
first_row = data_matrix[0, :]

print("Original Numeric Matrix:")
print(data_matrix)

print("\nExtracted Second Column:")
print(selected_column)

print("\nExtracted First Row:")
print(first_row)
