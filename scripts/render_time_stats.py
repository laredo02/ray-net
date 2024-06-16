
import re
import sys
import numpy as np
import matplotlib.pyplot as plt

# Read the log data from the console
log_data = sys.stdin.read()

# Extract time values from log data
time_pattern = r"time\s*=\s*(\d+)"
times = re.findall(time_pattern, log_data)
times = list(map(int, times))  # Convert to integers

# Calculate statistics
num_frames = len(times)
average_time = np.mean(times)
std_deviation = np.std(times)

# Print statistics
print(f"Number of frames: {num_frames}")
print(f"Average time: {average_time}")
print(f"Standard deviation: {std_deviation}")

# Create a histogram plot of time values
plt.figure(figsize=(10, 6))
plt.hist(times, bins=range(min(times), max(times) + 2), edgecolor='black', alpha=0.7)
plt.xlabel('Time')
plt.ylabel('Frequency')
plt.title('Histogram of Time Values')
plt.grid(True)
plt.xticks(np.arange(min(times), max(times) + 1, 1))
plt.show()

