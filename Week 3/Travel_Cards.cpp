#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define ll long long

using namespace std;

void solve()
{
	int n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;
	map<pair<string, string>, int> m;
	string s1, s2, c1, c2;
	for(int i = 0; i < n; i++)
	{
		cin >> c1 >> c2;
		int price = a;
		if(c1 == s2)	price = b;
		s1 = c1;
		s2 = c2;
		if(c1 > c2)	swap(c1, c2);
		if(m.count(make_pair(c1, c2)) == 0)
		{
			m[make_pair(c1, c2)] = price;
		}
		else
		{
			m[make_pair(c1, c2)] += price;
		}
	}
	
	vector<int> v;
	ll total = 0;
	for(auto p : m)
	{
		total += p.second;
		v.push_back(p.second);
	}
	ll ans = 0;
	sort(v.begin(), v.end(), greater<int> ());
	for(int i : v)
	{
		if(i >= f and k > 0)
		{
			k--;
			ans += f;
		}
		else
		{
			ans += i;
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