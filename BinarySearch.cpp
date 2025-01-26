#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
using namespace std;

#define ll long long

int binary_search(const vector<pair<string, string>>& records, const string& email) {
    int left = 0;
    int right = records.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // clock_t start = clock();
        if (records[mid].first == email) {
            // clock_t stop = clock();
            // double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
            // cout << "Time taken in success match: " << time_taken << " seconds" << endl;
            return mid;
        } else if (records[mid].first < email) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    FILE *read;
    vector<pair<string, string>> records;
    read = fopen("Record.txt", "r");
    char temp_s[100], temp_num[10];
    while (fscanf(read, "%s %s", temp_s, temp_num) != EOF) {
        // cout << temp_s << " " << temp_num << endl;
        records.push_back({temp_s, temp_num});
    }
    fclose(read);
    cout << "Total records read: " << records.size() << endl << records[0].first << " " << records[0].second << endl;

    clock_t start_sort = clock();
    sort(records.begin(), records.end());
    clock_t end_sort = clock();
    double sort_time = ((double)(end_sort - start_sort)) / CLOCKS_PER_SEC;
    cout << "Time taken to sort the records: " << sort_time << " seconds" << endl;

    vector<string> test_files = {"TestSet_100.txt", "TestSet_1000.txt", "TestSet_10000.txt", "TestSet_100000.txt"};

    ll tf = 0;
    for (const auto& test_file : test_files) {
        FILE *tread = fopen(test_file.c_str(), "r");
        if (!tread) {
            cerr << "Failed to open " << test_file << endl;
            continue;
        }

        vector<pair<string, string>> test_records;
        char temp_s[100], temp_num[10];
        while (fscanf(tread, "%s %s", temp_s, temp_num) != EOF) {
            test_records.push_back({temp_s, temp_num});
        }
        cout << "Total records read from " << test_file << ": " << test_records.size() << endl << test_records[0].first << " " << test_records[0].second << endl;

        float tot_time = 0;
        for (int t = 0; t < test_records.size(); t++) {
            clock_t start_search = clock();
            int index = binary_search(records, test_records[t].first);
            clock_t end_search = clock();

            if (index != -1) {
                // cout << "Found: " << records[index].second << endl;
                tf += 1;
                tot_time += ((double)(end_search - start_search)) / CLOCKS_PER_SEC;
            } else {
                // cout << "Not Found" << endl;
            }
            // break;
        }

        fclose(tread);

        cout << "Total time to search " << test_records.size() << " test data sets = " << tot_time << " seconds" << endl;
        cout << "Average time to search " << test_records.size() << " test data sets = " << tot_time / test_records.size() << " seconds" << endl;
    }
    cout << endl << tf << endl;
return 0;
}

/*
Total records read: 1000000
f6154chde873agb_@hotmail.com 9000000000
Time taken to sort the records: 1.16612 seconds
Total records read from TestSet_100.txt: 100
fd4c386h21a.ebg_75@rediffmail.com 9000959853
Total time to search 100 test data sets = 0.000288 seconds
Average time to search 100 test data sets = 2.88e-06 seconds
Total records read from TestSet_1000.txt: 1000
fd4c386h21a.ebg_75@rediffmail.com 9000959853
Total time to search 1000 test data sets = 0.00193901 seconds
Average time to search 100 test data sets = 1.93901e-06 seconds
Total records read from TestSet_10000.txt: 10000
fd4c386h21a.ebg_75@rediffmail.com 9000959853
Total time to search 10000 test data sets = 0.0245305 seconds
Average time to search 100 test data sets = 2.45305e-06 seconds
Total records read from TestSet_100000.txt: 100000
fd4c386h21a.ebg_75@rediffmail.com 9000959853
Total time to search 100000 test data sets = 0.207045 seconds
Average time to search 100 test data sets = 2.07045e-06 seconds

f6154chde873agb_@hotmail.com 9000000000
Time taken to sort the records: 1.26861 seconds
Total records read from TestSet_100.txt: 100
fd4c386h21a.ebg_75@rediffmail.com 9000959853
Time taken in success match: 1e-06 seconds
Total time to search 100 test data sets = 2.5e-05 seconds
Average time to search 100 test data sets = 2.5e-07 seconds
Total records read from TestSet_1000.txt: 1000
fd4c386h21a.ebg_75@rediffmail.com 9000959853
Time taken in success match: 0 seconds
Total time to search 1000 test data sets = 7e-06 seconds
Average time to search 100 test data sets = 7e-09 seconds
Total records read from TestSet_10000.txt: 10000
fd4c386h21a.ebg_75@rediffmail.com 9000959853
Time taken in success match: 1e-06 seconds
Total time to search 10000 test data sets = 1.4e-05 seconds
Average time to search 100 test data sets = 1.4e-09 seconds
Total records read from TestSet_100000.txt: 100000
fd4c386h21a.ebg_75@rediffmail.com 9000959853
Time taken in success match: 1e-06 seconds
Total time to search 100000 test data sets = 2.8e-05 seconds
Average time to search 100 test data sets = 2.8e-10 seconds

In binary search, std::string comparison uses optimized implementations (e.g., memcmp for character comparison), often outperforming manual character-by-character checks.

Sorting is a single, highly optimized operation with a complexity of 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn), while constructing a trie requires 
𝑂
(
𝑚
⋅
𝑛
)
O(m⋅n), where:
𝑛
n: Number of strings.
𝑚
m: Average string length.

Total records read: 1000000
f6154chde873agb_@hotmail.com 9000000000
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
*/