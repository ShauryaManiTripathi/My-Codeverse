import pandas as pd


Books_data = {
    'Subject': ['AI', 'Operating System', 'Chemistry', 'DBMS', 'AI', 'Economics'],
    'Book_Authors': ['shaurya', 'ritik', 'bhemm', 'ritik', 'shaurya', 'chutki'],
    'No_of_Books': [10, 25, 18, 22, 10, 16]
}

IIIT_Library = pd.DataFrame(Books_data)

sum_per_group = IIIT_Library.groupby('Subject')['No_of_Books'].sum()

print("Total number of books grouped by subject:")
print(sum_per_group)



