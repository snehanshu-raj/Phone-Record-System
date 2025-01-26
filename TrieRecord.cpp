#include<bits/stdc++.h>
#include<cstring>
#include<time.h>
using namespace std;

struct PackedTrie {
    // Edge label (compressed path) and reference to child nodes
    map<string, PackedTrie*> children;
    bool isLeaf = false;  // Indicates the end of a string
    string phoneNumber;   // Stores phone number if it's a leaf
};

// Insert into Packed Trie
void insert_packed(PackedTrie* root, const string& email, const string& number) {
    PackedTrie* node = root;
    int pos = 0;

    while (pos < email.length()) {
        string label;  // Label for the current edge
        bool found = false;

        for (auto& child : node->children) {
            label = child.first;

            // Find the longest common prefix between the label and the current suffix
            int common_length = 0;
            while (common_length < label.length() && pos + common_length < email.length() &&
                   label[common_length] == email[pos + common_length]) {
                common_length++;
            }

            // If there's a match
            if (common_length > 0) {
                found = true;

                if (common_length < label.length()) {
                    // Split the node if the match is partial
                    string remaining_label = label.substr(common_length);
                    PackedTrie* new_child = new PackedTrie();
                    new_child->children[remaining_label] = child.second;

                    child.second = new_child;
                    node->children.erase(label);
                    node->children[label.substr(0, common_length)] = new_child;
                }

                // Move to the next node
                node = child.second;
                pos += common_length;
                break;
            }
        }

        if (!found) {
            // Create a new edge if no match is found
            string suffix = email.substr(pos);
            PackedTrie* new_child = new PackedTrie();
            node->children[suffix] = new_child;
            node = new_child;
            break;
        }
    }

    // Mark the end of the email
    node->isLeaf = true;
    node->phoneNumber = number;
}

// Search in Packed Trie
string email_search_packed(PackedTrie* root, const string& email) {
    // cout << "Searching with: " << email << endl;
    PackedTrie* node = root;
    int pos = 0;

    while (pos < email.length()) {
        bool found = false;

        for (auto& child : node->children) {
            const string& label = child.first;

            if (email.substr(pos, label.length()) == label) {
                node = child.second;
                pos += label.length();
                found = true;
                break;
            }
        }

        if (!found) {
            return "0";  // Not found
        }
    }

    return (node->isLeaf) ? node->phoneNumber : "0";
}

// struct trie
// {
// 	map <char, struct trie *> reference;
// 	bool isLeaf = false;
// 	string PhoneNumber;
// };

// void insert(struct trie *root, string email, string number)
// {
// 	struct trie * trie_traverser = root;
	
// 	for(int i = 0; i < email.length(); i++)
// 	{
// 		char character = email[i];
// 		if((trie_traverser -> reference[character]) == NULL)
// 		{
// 			trie_traverser -> reference[character] = new trie;
// 		}
// 		trie_traverser = trie_traverser -> reference[character];		
// 	}
	
// 	trie_traverser -> isLeaf = true;
// 	trie_traverser -> PhoneNumber = number; 
// }

// string email_search (struct trie *root, string email)
// {
// 	struct trie * trie_traverser = root;

// 	// clock_t start = clock();
// 	for(int i = 0; i < email.length(); i++)
// 	{
// 		char character = email[i];
// 		if(trie_traverser -> reference[character] == NULL)
// 		{
// 			return "0";
// 		}
// 		trie_traverser = trie_traverser -> reference[character];
// 	}

// 	if	(trie_traverser != NULL && trie_traverser -> isLeaf == true) {
// 		// clock_t stop = clock();
// 		// double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
// 		// cout << "Time taken in success match: " << time_taken << " seconds" << endl;
// 		return trie_traverser -> PhoneNumber;
// 	}
// 	else return "0";
// }

int main()
{
	// struct trie *root = new trie;
	PackedTrie* root = new PackedTrie();

	FILE * tread;
	tread = fopen ("Test.txt", "r");

	FILE * read;
	read = fopen ("Record.txt", "r");
    vector<pair<string, string>> records;
    read = fopen("Record.txt", "r");
    char temp_s[100], temp_num[10];

	clock_t start_sort = clock();
    while (fscanf(read, "%s %s", temp_s, temp_num) != EOF) {
        records.push_back({temp_s, temp_num});
		// insert(root, temp_s, temp_num);
		insert_packed(root, temp_s, temp_num);
    }
	clock_t end_sort = clock();
    fclose(read);
	cout << "Total records read: " << records.size() << endl << records[0].first << " " << records[0].second << endl;
	double make_time = ((double)(end_sort - start_sort)) / CLOCKS_PER_SEC;
    cout << "Time taken to create tree: " << make_time << " seconds" << endl;

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
			string ans = email_search_packed (root, test_records[t].first);
			if (ans == "0")
				cout << " Not found" <<  endl;
			end = clock();
			// cout << ((float)end - (float)start) / CLOCKS_PER_SEC << endl;
			tot_time += ((float)end - (float)start) / CLOCKS_PER_SEC;
			// break;
		}
	
		cout << "Total time to search " << test_records.size() << " test data sets = " << tot_time << " seconds" << endl;
        cout << "Average time to search " << test_records.size() << " test data sets = " << tot_time / test_records.size() << " seconds" << endl;
    }
	delete root;
return 0;
}

/*
Total records read: 1000000
f6154chde873agb_@hotmail.com 9000000000
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

Total records read: 1000000
Time taken to create tree: 4.81968 seconds

Total records read from TestSet_100.txt: 100
Total time to search 100 test data sets = 0.000476 seconds
Average time to search 100 test data sets = 4.76e-06 seconds

Total records read from TestSet_1000.txt: 1000
Total time to search 1000 test data sets = 0.00389002 seconds
Average time to search 1000 test data sets = 3.89002e-06 seconds

Total records read from TestSet_10000.txt: 10000
Total time to search 10000 test data sets = 0.0869842 seconds
Average time to search 10000 test data sets = 8.69841e-06 seconds

Total records read from TestSet_100000.txt: 100000
Total time to search 100000 test data sets = 0.453673 seconds
Average time to search 100000 test data sets = 4.53673e-06 seconds
*/