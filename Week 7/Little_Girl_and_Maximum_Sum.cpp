#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first > p2.first;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	vector<int> cnt(n+1, 0);
	for(int i = 0; i < k; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		cnt[l]++;
		cnt[r]--;
	}
	for(int i = 1; i < n+1; i++)
	{
		cnt[i] += cnt[i-1];
	}
	vector<pair<int, int>> p;
	//first = no
	//second = index
	for(int i = 0; i < n; i++)
	{
		p.push_back({cnt[i], i});
	}
	sort(p.begin(), p.end(), compare);
	sort(a.begin(), a.end(), greater<int>());
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int x = p[i].first * a[i];
		ans += x;
	}
	cout<<ans;


}

int32_t main()
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