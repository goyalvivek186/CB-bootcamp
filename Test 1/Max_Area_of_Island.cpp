#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

int get(vector<vector<int>> &a, vector<vector<bool>>&dp, int m, int n, int i, int j)
{
	if(i < 0 or j < 0)		return 0;
	if(i >= m or j >= n)	return 0;
	if(dp[i][j] == true)	return 0;
	if(a[i][j] == 0)	return 0;
    dp[i][j] = true;
	int r = get(a, dp, m, n, i, j+1);
	int l = get(a, dp, m, n, i, j-1);
	int u = get(a, dp, m, n, i-1, j);
	int d = get(a, dp, m, n, i+1, j);
	return r + l + u + d + 1;
}

void solve()
{
	int m, n; 
	cin >> m >> n;
	vector<vector<int> > a(m, vector<int> (n, -1));
	vector<vector<bool> > dp(m, vector<bool> (n, false));
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)	cin >> a[i][j];
	}
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] == 0 or dp[i][j] == true)	continue;
			int x = get(a, dp, m, n, i, j);
			ans = max(ans, x);
		}
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