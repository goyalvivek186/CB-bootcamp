#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

vector<int> diStringMatch(string s) 
{
	vector<int> ans;
	int st = 0, e = s.length();
	int i = 0, j = e-1;
	while(i < s.length())
	{
		if(s[i] == 'I')
		{
			ans.push_back(st++);
			i++;
		}
		else
		{
			ans.push_back(e--);
			i++;
		}
	}
	ans.push_back(st);
	return ans;
}

int main()
{
	string s;
	cin >> s;
	vector<int> ans = diStringMatch(s);
	for(int i : ans)	cout<<i<<" ";	



	return 0;
}