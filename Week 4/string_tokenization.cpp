#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

void solve()
{
	string s = "My name is Vivek";
	char *tok = strtok((char*)s.c_str(), " ");
	while(tok != NULL)
	{
		cout<<tok<<endl;
		tok = strtok(NULL, " ");
	}

}

int main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}