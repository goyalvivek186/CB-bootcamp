#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

bool check(int *a, int *b)
{
	for(int i = 0; i < 26; i++)
	{
		if(a[i] != b[i])	return false;
	}
	return true;
}

vector<int> findAnagrams(string s, string p) 
{
	int sf[26] = {0};
	int pf[26] = {0};
	for(char ch : p)	pf[ch - 'a']++;
	int k = p.length();
	int i = 0;
	vector<int> ans;
	for(int j = 0; j < s.length(); j++)
	{
		char ch = s[j];
		sf[ch - 'a']++;
		if(j-i+1 == k)
		{
			if(check(sf, pf))
			{
				ans.push_back(i);
			}
			sf[s[i]-'a']--;
			i++;
		}
	}
	return ans;
}

int main()
{
	string s, p;
	cin >> s >> p;
	vector<int> ans = findAnagrams(s, p);
	for(int i : ans)	cout<<i<<" ";



	return 0;
}