#include<bits/stdc++.h>
#include<time.h>
#include<fstream>
using namespace std;

#define ll long long
int main()
{	
	string find;
	FILE * read;
	read = fopen ("Record.txt", "r");
	
	if (read == NULL) 
	{
		cout << "Could not open file" <<endl;
	}		
	
	while(1)
	{
		cin >> find;
		int f = 0;
		
		read = fopen ("Record.txt", "r");
		clock_t start, end;
		start = clock();
		for (int i = 0; i < 1000000; i++)
		{
			char temp_s[100];
			char temp_num[10];
			fscanf(read, "%s", temp_s);
			fscanf(read, "%s", temp_num);
		
			if(find == temp_s)
			{
				f = 1;
				cout << temp_num << " ";
				end = clock();
				cout << ((float)end - (float)start) / CLOCKS_PER_SEC << endl;
				fclose(read);
				break;
			}
		}
		if(f == 0)
		cout << "Not Found" << endl;
		fclose(read);
	}
return 0;
}
