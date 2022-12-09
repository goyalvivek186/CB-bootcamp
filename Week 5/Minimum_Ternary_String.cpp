#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

string get(string &s, int z, int o, int t)
{
	string ans;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '0' and ans.length() != 0)
		{
			ans.push_back('0');
			z--;
		}
		else if(s[i] == '2')
		{
			ans.push_back('2');
		}
	}

	for(int i = 0; i < o; i++)	ans = '1' + ans;
	for(int i = 0; i < z; i++)	ans = '0' + ans;
	return ans;
}


void solve()
{
	string s;
	cin >> s;
	int o, z, t;
	o = t = z = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '0')			z++;
		else if(s[i] == '1')	o++;
		else					t++;
	}
	string ans;
	if(t == 0)
	{
		for(int i = 0; i < z; i++)	ans.push_back('0');
		for(int i = 0; i < o; i++)	ans.push_back('1');
	}
	else
	{
		ans = get(s, z, o, t);
	}
	cout<<ans;
}

int main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
		// cout<<endl;
	}

	return 0;
}