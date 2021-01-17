#include<bits/stdc++.h>
#include<fstream>
#include<cstring>

#define ll unsigned long long

using namespace std;

int main()
{
	ofstream read[1000];
	char buffer[33];

	FILE *record_read;
	record_read = fopen ("Record.txt", "r");
	
	for(ll i = 0; i < 1000000; i++)
	{
		char temp_s[100];
		char temp_num[10];
		fscanf(record_read, "%s", temp_s);
		fscanf(record_read, "%s", temp_num);
		
		ll remainder = atoll(temp_num) % 1000;
		
		read[remainder].open(ltoa(remainder, buffer, 10), std::ios::app);
		
		read[remainder] << temp_s << " " << temp_num << endl;
		cout << "done" << endl;	
		read[remainder].close();		
	}

	fclose(record_read);
return 0;
}
