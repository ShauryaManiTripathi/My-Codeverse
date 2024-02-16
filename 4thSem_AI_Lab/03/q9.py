import numpy as np

matrix_dimension = 3
coeff_matrix = np.random.rand(matrix_dimension, matrix_dimension)
constant_vector = np.random.rand(matrix_dimension)
solution_vector = np.linalg.solve(coeff_matrix, constant_vector)

print("Random Coefficient Matrix:")
print(coeff_matrix)

print("\nRandom Constant Vector:")
print(constant_vector)

print("\nCalculated Solution Vector:")
print(solution_vector)
