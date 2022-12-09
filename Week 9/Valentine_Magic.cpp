#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <set>
#include <climits>

#define int long long

using namespace std;

int get(vector<int> &b, vector<int> &g, int i, int j, int s, vector<vector<int>> &dp)
{
	if(i == b.size())
	{
		return 0;
	}
	if(j == g.size())
	{
		return INT_MAX;
	}
	if(dp[i][j] != -1)	return dp[i][j];
	//exlucde
	int op1 = 0 + get(b, g, i, j+1, s, dp);

	//include
	int op2 = abs(b[i] - g[j]) + get(b, g, i+1, j+1, s, dp);

	return dp[i][j] = min(op1, op2);

}

void solve()
{
	int m, n;
	cin >> m >> n;
	vector<int> b(m, 0);
	for(int i = 0; i < m; i++)	cin >> b[i];
	vector<int> g(n, 0);
	for(int i = 0; i < n; i++)	cin >> g[i];

	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	vector<vector<int>> dp(m, vector<int> (n, -1)); 
	
	cout<<get(b, g, 0, 0, 0, dp);



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