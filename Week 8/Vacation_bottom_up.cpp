#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

int get(vector<int> &a, vector<int> &b, vector<int> &c, vector<vector<int>> &dp, int i, int j)
{
	if(i == 0)
	{
		if(j == 0)	return max(dp[0][1], dp[0][2]);
		if(j == 1)	return max(dp[0][0], dp[0][2]);
		if(j == 2)	return max(dp[0][0], dp[0][1]);
	}


	if(dp[i][j] != -1)	return dp[i][j];

	int op1, op2;
	int ans = 0;
	if(j == 0)
	{
		op1 = get(a, b, c, dp, i-1, 1);
		op2 = get(a, b, c, dp, i-1, 2);
		ans = a[i] + max(op1, op2);
	}
	else if(j == 1)
	{
		op1 = get(a, b, c, dp, i-1, 0);
		op2 = get(a, b, c, dp, i-1, 2);
		ans = b[i] + max(op1, op2);
	}
	else if(j == 2)
	{
		op1 = get(a, b, c, dp, i-1, 0);
		op2 = get(a, b, c, dp, i-1, 1);
		ans = c[i] + max(op1, op2);
	}

	return dp[i][j] = ans;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; i++)	cin >> a[i] >> b[i] >> c[i];

	vector<vector<int> > dp(n, vector<int> (3, -1));
	
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];

	if(n == 1)
	{
		cout<< max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
		return;
	}

	dp[n-1][0] = get(a, b, c, dp, n-1, 0);
	dp[n-1][1] = get(a, b, c, dp, n-1, 1);
	dp[n-1][2] = get(a, b, c, dp, n-1, 2);

	cout<< max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

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