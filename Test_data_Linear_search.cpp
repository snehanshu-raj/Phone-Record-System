#include<bits/stdc++.h>
#include<fstream>
#include<time.h>
using namespace std;

#define ll long long

int main()
{
	FILE * tread;
	tread = fopen ("Test.txt", "r");
	FILE * read;
	read = fopen ("Record.txt", "r");
	
	float avg_time = 0;
	
	if (tread == NULL) 
	{
		cout << "Could not open file" <<endl;
	}		
	
	for(int t = 0; t < 100; t++)
	{	
		char finde[100];
		char num[10];
		fscanf(tread, "%s", finde);
		fscanf(tread, "%s", num);
		
		read = fopen ("Record.txt", "r");
		
		clock_t start, end;
		start = clock();
		
		int f = 0;
		for (ll i = 0; i < 1000000; i++)
		{
			char temp_s[100];
			char temp_num[10];
			fscanf(read, "%s", temp_s);
			fscanf(read, "%s", temp_num);
		
			if(strcmp(finde, temp_s) == 0)
			{ 
				f = 1;
				cout << temp_num << " ";
				end = clock();
				cout << ((float)end - (float)start) / CLOCKS_PER_SEC << endl;
				avg_time += ((float)end - (float)start) / CLOCKS_PER_SEC;
				fclose(read);
				break;
			}
		}
		if(f == 0)
		cout << "Not Found" << endl;
		fclose(read);
	}
	fclose(tread);
	
	cout << "total time to linearly search 100 test data set = " << avg_time << endl;
	cout << "average time to linearly search 100 test data set = " << avg_time / 100 << endl;
return 0;
}
