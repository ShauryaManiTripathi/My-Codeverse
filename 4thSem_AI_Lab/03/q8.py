import numpy as np

data_matrix = np.array([[2, 4, 6, 8, 10, 12],
                       [5, 6, 8, 10, 12, 14],
                       [2, 4, 6, 8, 10, 12],
                       [10, 12, 14, 16, 18, 20],
                       [2, 4, 6, 8, 10, 12]])

flattened_data = data_matrix.flatten()

unique_values, counts = np.unique(flattened_data, return_counts=True)

frequency_info = dict(zip(unique_values, counts))

print("Modified 2D Data Matrix:")
print(data_matrix)

print("\nFrequency of Repeated Numbers:")
for num, freq in frequency_info.items():
    print(f"Number {num}: {freq} times")
