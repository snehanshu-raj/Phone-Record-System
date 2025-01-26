#include <bits/stdc++.h>
#include <cstring>
#include <time.h>
using namespace std;

struct PackedTrie {
    // Edge label (compressed path) and reference to child nodes
    map<string, PackedTrie*> children;
    bool isLeaf = false;  // Indicates the end of a string
    string phoneNumber;   // Stores phone number if it's a leaf
};

// Insert into Packed Trie
void insert(PackedTrie* root, const string& email, const string& number) {
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
string email_search(PackedTrie* root, const string& email) {
    cout << "Searching with: " << email << endl;
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

int main() {
    PackedTrie* root = new PackedTrie();

	FILE * read;
    vector<pair<string, string>> records;
    read = fopen("Record.txt", "r");
    char temp_s[100], temp_num[10];

	clock_t start_sort = clock();
    while (fscanf(read, "%s %s", temp_s, temp_num) != EOF) {
        records.push_back({temp_s, temp_num});
		insert(root, temp_s, temp_num);
    }
    clock_t end_sort = clock();
    fclose(read);
    cout << records[0].first << " " << records[0].second << endl;
    cout << "Total records read: " << records.size() << endl;
    cout << "Time taken to create packed trie: " << ((double)(end_sort - start_sort)) / CLOCKS_PER_SEC << " seconds" << endl;

    // Search test records
    // vector<string> test_files = {"TestSet_100.txt", "TestSet_1000.txt", "TestSet_10000.txt", "TestSet_100000.txt"};

    // for (const auto& test_file : test_files) {
    //     FILE* tread = fopen(test_file.c_str(), "r");
    //     if (!tread) {
    //         cerr << "Failed to open " << test_file << endl;
    //         continue;
    //     }

    //     vector<pair<string, string>> test_records;
    //     while (fscanf(tread, "%s %s", temp_s, temp_num) != EOF) {
    //         test_records.push_back({temp_s, temp_num});
    //     }
    //     fclose(tread);

    //     cout << "Total records read from " << test_file << ": " << test_records.size() << endl;

    //     float tot_time = 0;
    //     for (const auto& record : test_records) {
    //         clock_t start = clock();
    //         cout << "Searching with: " << record.first << endl;
    //         string ans = email_search(root, record.first);
    //         cout << ans << " ";
    //         clock_t end = clock();
    //         tot_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    //     }

    //     cout << "Total time to search " << test_records.size() << " test data sets = " << tot_time << " seconds" << endl;
    //     cout << "Average time to search " << test_records.size() << " test data sets = " << tot_time / test_records.size() << " seconds" << endl;
    // }

    delete root;
    return 0;
}
