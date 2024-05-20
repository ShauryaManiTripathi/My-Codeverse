import random

def generate_test_case():
    n = random.randint(90000, 100000)  # Generates a random number between 1 and 10 for n
    inputs = [random.randint(1000, 20000) for _ in range(n)]  # Generates n random integers between -100 and 100
    return n, inputs

def write_test_case_to_file(filename, n, inputs):
    with open(filename, 'w') as file:
        file.write(str(n) + '\n')
        file.write(' '.join(map(str, inputs)) + '\n')

# Generate test case
n, inputs = generate_test_case()

# Write test case to file
write_test_case_to_file('input', n, inputs)
