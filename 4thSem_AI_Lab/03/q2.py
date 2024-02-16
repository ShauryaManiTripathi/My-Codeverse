import pandas as pd

# Define book data with modified names and values
library_data = {
    'Field': ['Artificial Intelligence', 'Operating Systems', 'Chemistry', 'Database Management', 'Artificial Intelligence', 'Economics'],
    'Authors': ['Alex', 'Ryan', 'Emma', 'Ryan', 'Alex', 'Sophie'],
    'Quantity': [15, 30, 20, 25, 15, 18]
}

university_library = pd.DataFrame(library_data)

sum_per_category = university_library.groupby('Field')['Quantity'].sum()

print("Total quantity of books grouped by field:")
print(sum_per_category)
