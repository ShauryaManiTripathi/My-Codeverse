import pandas as pd

# Define student data with modified names and values
student_info = {
    'Student_Name': ['Alice', 'Bob', 'Charlie', 'Diana', 'Eva'],
    'Roll_Number': [220201, 220202, 220203, 220204, 220205],
    'Cumulative_GPA': [8.1, 7.5, 6.9, 8.4, 7.2]
}

# Create DataFrame
student_df = pd.DataFrame(student_info)

# Filter DataFrame where Cumulative GPA > 7.0
filtered_student_df = student_df[student_df['Cumulative_GPA'] > 7.0]

# Calculate mean, median, and standard deviation of Cumulative GPA
mean_gpa = student_df['Cumulative_GPA'].mean()
median_gpa = student_df['Cumulative_GPA'].median()
std_gpa = student_df['Cumulative_GPA'].std()

# Print filtered DataFrame and statistics
print("Filtered DataFrame where Cumulative GPA > 7.0:")
print(filtered_student_df)
print("\nMean Cumulative GPA:", mean_gpa)
print("Median Cumulative GPA:", median_gpa)
print("Standard Deviation of Cumulative GPA:", std_gpa)
