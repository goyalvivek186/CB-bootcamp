#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
// #include <climits>

#define int long long

using namespace std;

void get(vector<int> &a, int n, int t, int s, set<vector<int>> &st, vector<int> cur, int i)
{
	if(s == t)
	{
		st.insert(cur);
		return;
	}
	if(s > t)				return;
	if(i == n)				return;
	// if(a[i] > t-s)			return;
	if(cur.size() > 5550)	return;
	get(a, n, t, s, st, cur, i+1);
	s += a[i];
	cur.push_back(a[i]);
	get(a, n, t, s, st, cur, i);
	get(a, n, t, s, st, cur, i+1);

}

void solve()
{
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	set<vector<int>> st;
	vector<int> cur;
	int s = 0;
	get(a, n, t, s, st, cur, 0);
	cout<<st.size();

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