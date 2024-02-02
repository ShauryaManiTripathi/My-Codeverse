import pandas as pd

Student_Data = {
    'Std_Name': ['shaurya', 'ritik', 'bheem', 'chutki', 'dholu'],
    'Roll_no': [220101, 2201102, 2201103, 2201104, 2201105],
    'CPI': [7.2, 8.3, 5.4, 6.85, 7.53]
}

df = pd.DataFrame(Student_Data)


filtered_df = df[df['CPI'] > 6.0]


mean = df['CPI'].mean()
median = df['CPI'].median()
std = df['CPI'].std()

print("Filtered DataFrame where CPI > 6.0:")
print(filtered_df)
print("\n Mean CPI:", mean)
print("Median CPI:", median)
print("Standard Deviation of CPI:", std)
