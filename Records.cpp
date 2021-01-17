#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define ll long long

int main()
{
	ofstream write, twrite;
	write.open("Record.txt");
	twrite.open("Test.txt");
	
	srand(time(0));
	ll n = 9000000000;
	char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '1', '2', '3', '4', '5', '6', '7', '8', '.', '_'};
	string email_id[] = {"@gmail.com", "@yahoo.com", "@hotmail.com", "@rediffmail.com"};
	
	for(ll i = 0; i < 1000000; i++)
	{
		random_shuffle(letters, letters + 18);
		
 		string s = letters;
 		string email;
 		
		if(s[0] == '.' || s[0] == '_')
 		email = s.substr(1, (rand() % 10) + 9) + email_id[ rand() % 4 ];
 		else
 		email = s.substr(0, (rand() % 10) + 9) + email_id[ rand() % 4 ];
 		
		write << email << " ";
		write << n + i << endl;	
		
		if(i % 10000 == 0)
		{
			twrite << email << " ";
			twrite << n + i << endl;
		}	
	}
	write.close();
	twrite.close();
return 0;
}
