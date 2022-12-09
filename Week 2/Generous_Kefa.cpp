#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
	int n, k;	cin >> n >> k;
	unordered_map<char, int> m;
	for(int i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;
		if(m.count(ch) == 0)	m[ch] = 1;
		else					m[ch]++;
	}

	int d = n/k;
    // cout<<d<<endl;
	vector<int> cnt;
	for(pair<char, int> p : m)
	{
		cnt.push_back(p.second);
	}
	int i;
	for(i = 0; i < cnt.size(); i++)
	{
		if(cnt[i] > k)	break;
	}

	if(i == cnt.size())		cout<<"YES";
	else					cout<<"NO";	


	return 0;
}