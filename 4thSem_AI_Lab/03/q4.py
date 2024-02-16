import pandas as pd

employee_info = {'Employee_Name': ['Alex', 'Violet', 'Oliver', 'Sophie'],
                 'Employee_Age': [28, 20, 35, 25],
                 'Monthly_Salary': [60000, 1200, 80000, 65000]}

uncleaned_records = pd.DataFrame(employee_info)

cleaned_records = uncleaned_records[(uncleaned_records['Employee_Age'] >= 18) & (uncleaned_records['Monthly_Salary'] >= 0)]

print("Original Employee Records:")
print(uncleaned_records)

print("\nCleaned Employee Records:")
print(cleaned_records)
