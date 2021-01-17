#include<bits/stdc++.h>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	srand(time(0));
	char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '1', '2', '3', '4', '5', '6', '7', '8', '.', '_'};
	
	for(int i = 0; i < 10; i++)
	{
		random_shuffle(letters, letters + 18);
		string s = letters;
		cout << s.substr(0, (rand() % 10) + 9) << endl;
	}
return 0;
}
