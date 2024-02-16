import numpy as np
import time

# Define matrix dimensions
num_rows = 106
num_cols = 104

# Generate random matrices P and Q
matrix_P = np.random.rand(num_rows, num_cols)
matrix_Q = np.random.rand(num_rows, num_cols)

# Matrix multiplication using nested loops
start_time_loop = time.time()
result_loop = np.zeros((num_rows, num_rows))
for i in range(num_rows):
    for j in range(num_rows):
        for k in range(num_cols):
            result_loop[i, j] += matrix_P[i, k] * matrix_Q[j, k]
end_time_loop = time.time()
loop_execution_time = end_time_loop - start_time_loop

# Matrix multiplication using vectorized operations
start_time_vec = time.time()
result_vec = np.dot(matrix_P, matrix_Q.T)
end_time_vec = time.time()
vectorized_execution_time = end_time_vec - start_time_vec

# Calculate speedup
speedup_factor = loop_execution_time / vectorized_execution_time

print("Matrix multiplication with Q transpose using loops:")
print(result_loop)

print("\nMatrix multiplication with Q transpose using vectorized operations:")
print(result_vec)

print("\nSpeedup Factor:", speedup_factor)
