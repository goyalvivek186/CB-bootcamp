#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

void solve()
{
	vector<string> s; 
	char ch[] = "My name is Vivek Goyal";
	char *tok = strtok(ch, " ");
	// cout<<tok;
	s.push_back(tok);
	while(tok != NULL)
	{
		s.push_back(tok);
        cout<<tok<<endl;
		tok = strtok(NULL, " ");
		
	}
	cout<<endl;
	for(int i = 0; i < s.size(); i++)
	{
		cout<<s[i]<<" ";
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