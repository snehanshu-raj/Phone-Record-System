import matplotlib.pyplot as plt
import numpy as np

# Test sizes
test_sizes = ['100', '1,000', '10,000', '100,000']

# Data for Trie Tree
trie_creation_time = 19.4174
trie_search_times = [0.000776, 0.00750604, 0.088561, 0.800438]

# Data for Packed Trie Tree
packed_trie_creation_time = 4.81968
packed_trie_search_times = [0.000476, 0.00389002, 0.0869842, 0.453673]

# 1. Plot search times for each test size (individual plots)
for i, test_size in enumerate(test_sizes):
    # Create a figure
    fig, ax = plt.subplots(figsize=(8, 6))

    # X-axis positions for the two bars
    x = np.arange(2)

    # Heights for the bars (search times)
    search_times = [trie_search_times[i], packed_trie_search_times[i]]

    # Bar labels
    labels = ['Trie Tree', 'Packed Trie Tree']

    # Bar widths
    bar_width = 0.4

    # Plot search times
    search_bars = ax.bar(
        x, search_times, width=bar_width, label='Search Times', color=['skyblue', 'orange']
    )

    # Annotate bars with time values
    for bar, time in zip(search_bars, search_times):
        height = bar.get_height()
        ax.text(
            bar.get_x() + bar.get_width() / 2,  # X position
            height * 0.2,  # Y position
            f'{time:.6f} sec',  # Time value
            ha='center',
            va='bottom',
            fontsize=9,
            color='black'
        )

    # Add labels, title, and legend
    ax.set_xlabel('Data Structures', fontsize=12)
    ax.set_ylabel('Search Times (seconds)', fontsize=12)
    ax.set_title(f'Search Time Comparison for {test_size} Records', fontsize=14)
    ax.set_xticks(x)
    ax.set_xticklabels(labels)

    # Add gridlines for better readability
    ax.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)

    # Adjust layout and show the plot
    # plt.tight_layout()
    plt.savefig(f'trie_vs_packedtrie_{i}.png')

# 2. Plot creation times in a single plot
fig, ax = plt.subplots(figsize=(8, 6))

# X-axis positions
x = np.arange(2)

# Heights for the bars (creation times)
creation_times = [trie_creation_time, packed_trie_creation_time]

# Bar labels
labels = ['Trie Tree', 'Packed Trie Tree']

# Bar widths
bar_width = 0.4

# Plot creation times
creation_bars = ax.bar(
    x, creation_times, width=bar_width, color=['skyblue', 'orange']
)

# Annotate bars with time values
for bar, time in zip(creation_bars, creation_times):
    height = bar.get_height()
    ax.text(
        bar.get_x() + bar.get_width() / 2,  # X position
        height + 0.0005,  # Y position
        f'{time:.2f} sec',  # Time value
        ha='center',
        va='bottom',
        fontsize=9,
        color='black'
    )

# Add labels, title, and legend
ax.set_xlabel('Data Structures', fontsize=12)
ax.set_ylabel('Creation Times (seconds)', fontsize=12)
ax.set_title('Creation Time Comparison for Trie Tree and Packed Trie Tree', fontsize=14)
ax.set_xticks(x)
ax.set_xticklabels(labels)

# Add gridlines for better readability
ax.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)

# Adjust layout and show the plot
plt.tight_layout()
plt.savefig('trie_vs_packedtrie_creation.png')
# plt.show()

'''
Data for Linear search:
Total records read from TestSet_100.txt: 100
total time to linearly search 100 test data set = 0.900736
average time to linearly search 100 test data set = 0.00900736

Total records read from TestSet_1000.txt: 1000
total time to linearly search 1000 test data set = 9.13955
average time to linearly search 1000 test data set = 0.00913955

Total records read from TestSet_10000.txt: 10000
total time to linearly search 10000 test data set = 90.056
average time to linearly search 10000 test data set = 0.00900559

Total records read from TestSet_100000.txt: 100000
total time to linearly search 100000 test data set = 888.69
average time to linearly search 100000 test data set = 0.0088869

Data for Binary search:
Total records read: 1000000
Time taken to sort the records: 1.42891 seconds

Total records read from TestSet_100.txt: 100
Total time to search 100 test data sets = 0.000329 seconds
Average time to search 100 test data sets = 3.29e-06 seconds

Total records read from TestSet_1000.txt: 1000
Total time to search 1000 test data sets = 0.00234501 seconds
Average time to search 1000 test data sets = 2.34501e-06 seconds

Total records read from TestSet_10000.txt: 10000
Total time to search 10000 test data sets = 0.029638 seconds
Average time to search 10000 test data sets = 2.9638e-06 seconds

Total records read from TestSet_100000.txt: 100000
Total time to search 100000 test data sets = 0.267882 seconds
Average time to search 100000 test data sets = 2.67882e-06 seconds

Data for Trie search:
Total records read: 1000000
Time taken to create tree: 19.4174 seconds

Total records read from TestSet_100.txt: 100
Total time to search 100 test data sets = 0.000776 seconds
Average time to search 100 test data sets = 7.76e-06 seconds

Total records read from TestSet_1000.txt: 1000
Total time to search 1000 test data sets = 0.00750604 seconds
Average time to search 1000 test data sets = 7.50604e-06 seconds

Total records read from TestSet_10000.txt: 10000
Total time to search 10000 test data sets = 0.088561 seconds
Average time to search 10000 test data sets = 8.8561e-06 seconds

Total records read from TestSet_100000.txt: 100000
Total time to search 100000 test data sets = 0.800438 seconds
Average time to search 100000 test data sets = 8.00438e-06 seconds
'''