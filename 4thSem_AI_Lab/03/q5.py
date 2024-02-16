import pandas as pd

# Define time-related data with modified names and values
schedule_data = {'Event_Time': ['2024-02-03 09:15:00', '2024-02-03 16:30:00', '2024-02-03 23:45:00']}
schedule_df = pd.DataFrame(schedule_data)
schedule_df['Event_Time'] = pd.to_datetime(schedule_df['Event_Time'])

schedule_df['Scheduled_Hour'] = schedule_df['Event_Time'].dt.hour

print("Original Schedule DataFrame:")
print(schedule_df[['Event_Time']])

print("\nSchedule DataFrame with 'Scheduled_Hour' column:")
print(schedule_df[['Event_Time', 'Scheduled_Hour']])
