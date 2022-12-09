#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

bool check(string &s, int i)
{
	if(i == s.size())	return true;
	if(s[i] == 'a')
	{
		return check(s, i+1);
	}
	else if(s[i] == 'b')
	{
		if(i+1 == s.size() or s[i+1] != 'b')	return false;
		if(i+2 == s.size())	return true;
		if(s[i+2] == 'b')	return false;

		return check(s, i+2);
	}
	return false;
}


void solve()
{
	string s;
	cin >> s;
	if(s.size() == 0)
	{
		cout<<"true";
		return;
	}	
	if(s[0] != 'a')
	{
		cout<<"false";
		return;
	}
	bool ans = check(s, 0);
	if(ans)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}

}

int main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}