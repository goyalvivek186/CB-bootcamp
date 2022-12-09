#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>

#define ll long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[x]++;
	}
	int ans = 0;
	for(pair<int, int> p : m)
	{
		if(p.first == p.second)	continue;

		if(p.first > p.second)
		{
			ans += p.second;
		}
		else
		{
			ans += p.second - p.first;
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

		// cout<<endl;
	}

	return 0;
}