#include<bits/stdc++.h>
#include<cstring>
#include<time.h>
using namespace std;

struct trie
{
	map <char, struct trie *> reference;
	bool isLeaf = false;
	string PhoneNumber;
};

void insert(struct trie *root, string email, string number)
{
	struct trie * trie_traverser = root;
	
	for(int i = 0; i < email.length(); i++)
	{
		char character = email[i];
		if((trie_traverser -> reference[character]) == NULL)
		{
			trie_traverser -> reference[character] = new trie;
		}
		trie_traverser = trie_traverser -> reference[character];		
	}
	
	trie_traverser -> isLeaf = true;
	trie_traverser -> PhoneNumber = number; 
}

string email_search (struct trie *root, string email)
{
	struct trie * trie_traverser = root;
	for(int i = 0; i < email.length(); i++)
	{
		char character = email[i];
		if(trie_traverser -> reference[character] == NULL)
		{
			return "0";
		}
		trie_traverser = trie_traverser -> reference[character];
	}

	if	(trie_traverser != NULL && trie_traverser -> isLeaf == true)
		return trie_traverser -> PhoneNumber;
	else
		return "0";
}

int main()
{
	struct trie *root = new trie;
	
	FILE * tread;
	tread = fopen ("Test.txt", "r");
	FILE * read;
	read = fopen ("Record.txt", "r");
	
	if (read == NULL) 
	{
		cout << "Could not open file" <<endl;
	}		
	
	long long i;
	for(i = 0; i < 1000000; i++)
	{
		char email[100];
		char number[10];
		fscanf(read, "%s", email);
		fscanf(read, "%s", number);
		
		insert(root, email, number);
	}
	
	float avg_time = 0;	
	for(int t = 0; t < 100; t++)
	{	
		char test_email[100];
		char test_num[10];
		fscanf(tread, "%s", test_email);
		fscanf(tread, "%s", test_num);
		
		clock_t start, end;
		
		start = clock();
		string ans = email_search (root, test_email);
		cout << ans << " ";
		end = clock();
		
		cout << ((float)end - (float)start) / CLOCKS_PER_SEC << endl;
		avg_time += ((float)end - (float)start) / CLOCKS_PER_SEC;
	}
	
	cout << "Total time to search 100 test data set using trie data structure = " << avg_time << endl;
	cout << "Average time to search 100 test data set using trie data structure =  " << avg_time / 100 << endl;
	delete root;
return 0;
}
