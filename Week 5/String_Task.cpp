#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

//vowels -  "A", "O", "Y", "E", "U", "I"

bool check_vowels(char ch)
{
	string s = "aoyeui";
	for(int i = 0; i < s.length(); i++)
	{
		if(ch == s[i])	return true;
	}
	return false;
}

void solve()
{
	string s;
	cin >> s;
	string ans;
	for(int i = 0; i < s.length(); i++)
	{
		char ch = tolower(s[i]);
		if(check_vowels(ch))
		{
			continue;
		}
		else
		{
			ans.push_back('.');
			ans.push_back(ch);
		}
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
	}

	return 0;
}