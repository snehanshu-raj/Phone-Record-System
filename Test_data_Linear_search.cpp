#include<bits/stdc++.h>
#include<fstream>
#include<time.h>
using namespace std;

#define ll long long

void generate_test_set(const vector<pair<string, string>>& records, ll number) {
    srand(time(0));
    vector<int> selected_indices;

    while (selected_indices.size() < number) {
        int index = rand() % records.size();
        if (find(selected_indices.begin(), selected_indices.end(), index) == selected_indices.end()) {
            selected_indices.push_back(index);
        }
		cout << "Generated and pushed: " << index << " Size: " << selected_indices.size() << endl;
    }
    for (ll i = 0; i < selected_indices.size(); i++) {
        cout << selected_indices[i] << " ";
    }
    cout << endl;

    stringstream ss;
    ss << "TestSet_" << number << ".txt";
    string filename = ss.str();
    ofstream output_file(filename);
    for (ll i = 0; i < number; i++) {
        ll index = selected_indices[i];
        output_file << records[index].first << " " << records[index].second << endl;
		cout << "Written: " << i << endl;
    }

    output_file.close();
    cout << number << " random records have been written to " << filename << endl;
}

int main()
{
	FILE *read;
    vector<pair<string, string>> records;
    read = fopen("Record.txt", "r");
    char temp_s[100], temp_num[10];
    while (fscanf(read, "%s %s", temp_s, temp_num) != EOF) {
        records.push_back({temp_s, temp_num});
    }
    fclose(read);
	cout << "Total records read: " << records.size() << endl << records[0].first << " " << records[0].second << endl;

	// generate_test_set(records, 100);
	// cout << "Total records read: " << records.size() << endl << records[0].first << " " << records[0].second << endl;
    // generate_test_set(records, 1000);
	// cout << "Total records read: " << records.size() << endl << records[0].first << " " << records[0].second << endl;
    // generate_test_set(records, 10000);
	// cout << "Total records read: " << records.size() << endl << records[0].first << " " << records[0].second << endl;
    // generate_test_set(records, 100000);
	// cout << "Total records read: " << records.size() << endl << records[0].first << " " << records[0].second << endl;
    // generate_test_set(records, 1000000);
	// cout << "Total records read: " << records.size() << endl << records[0].first << " " << records[0].second << endl;

	vector<string> test_files = {"TestSet_100.txt", "TestSet_1000.txt", "TestSet_10000.txt", "TestSet_100000.txt"};

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
		for(int t = 0; t < test_records.size(); t++)
		{				
			clock_t start, end;
			start = clock();
			
			int f = 0;
			for (ll i = 0; i < records.size(); i++)
			{
				// cout << "Searching with: " << records[i].first << endl;
				// cout << "Comparing with: " << finde << endl;

				if(test_records[t].first == records[i].first)
				{ 
					f = 1;
					// cout << temp_num << " ";
					end = clock();
					// cout << ((float)end - (float)start) / CLOCKS_PER_SEC << endl;
					tot_time += ((float)end - (float)start) / CLOCKS_PER_SEC;
					break;
				}
			}
			if(f == 0)
				cout << "Not Found" << endl;
		}
		fclose(tread);
		
		cout << "total time to linearly search 100 test data set = " << tot_time << endl;
		cout << "average time to linearly search 100 test data set = " << tot_time / test_records.size() << endl;
	}
return 0;
}

/*
Total records read: 1000000

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
*/