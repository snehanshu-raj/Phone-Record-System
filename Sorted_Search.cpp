#include<bits/stdc++.h>
#include<fstream>
#include<cstring>
#include<time.h>
using namespace std;
namespace fs = std::filesystem;

#define ll unsigned long long


int main()
{
	FILE * tread;
	tread = fopen ("Test.txt", "r");
	
	float avg_time = 0;
	char buffer[33];
	
	for(int i = 0; i < 100; i++)
	{
		char finde[100];
		char num[10];
		fscanf(tread, "%s", finde);
		fscanf(tread, "%s", num);
		
		ll remainder = atoll(num) % 1000;
		string filepath = "bucket_records/" + to_string(remainder);

		// FILE * dread;

		// sprintf(buffer, "%llu", remainder);
		// dread = fopen(buffer, "r");

		FILE *dread = fopen(filepath.c_str(), "r");
		
		clock_t start, end;
		start = clock();
		while(dread)
		{
			char temp_s[100];
			char temp_num[10];
			fscanf(dread, "%s", temp_s);
			fscanf(dread, "%s", temp_num);
			
			if(strcmp(temp_num, num) == 0)
			{
				cout << temp_s << " ";
				end = clock();
				cout << ((float)end - (float)start) / CLOCKS_PER_SEC << endl;
				avg_time += ((float)end - (float)start) / CLOCKS_PER_SEC;
				fclose(dread);
				break;
			}
		}
	}
	fclose(tread);
	
	cout << "total time to linearly search 100 test data set = " << avg_time << endl;
	cout << "average time to linearly search 100 test data set = " << avg_time / 100 << endl;
}
