#include <iostream>
#include <vector>
// #include <string>
#include <algorithm>
#include <map>
#include <set>
// #include <climits>

#define int long long

using namespace std;

void get(vector<int> &a, int n, map<int, set<vector<int> > > &m, int i, int cnt, int s, vector<int> cur)
{
	if(cnt == 2)
	{
		m[s].insert(cur);
		return;
	}
	if(i >= n)	return;
	get(a, n, m, i+1, cnt, s, cur);	//exclude

	s += a[i];
	cnt++;
	cur.push_back(a[i]);
	get(a, n, m, i+1, cnt, s, cur);	//include
	cur.pop_back();

}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	map<int, set<vector<int> >> m;
	vector<int> cur;
	get(a, n, m, 0, 0, 0, cur);

	int ans = 0;
	for(auto it : m)
	{
		// cout<<it.first<<" "<<it.second.size()<<endl;
		if(it.second.size() > ans and it.first != 0)	ans = it.second.size();
	}
	cout<<ans;
	
	
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}