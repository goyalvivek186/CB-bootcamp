#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.second == p2.second)
	{
		return p1.first > p2.first;
	}
	return p1.second < p2.second;

}


void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i].first = x;
		a[i].second = y;
	} 

	sort(a.begin(), a.end(), compare);

	int cnt = 1;
	int cur = a[0].second;
	for(int i = 1; i < n; i++)
	{
		if(a[i].first >= cur)
		{
			cnt++;
			cur = a[i].second;
		}
	}
	cout<<cnt;

}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}