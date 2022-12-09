#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define mod 1000000007
#define int long long

using namespace std;

int get(int i, int k, vector<int> &dp)
{
	if(i == 0)	return 1;	//the current arrangement has been completed
	
	if(dp[i] != -1)	return dp[i];

	int op1, op2;
	op1 = op2 = 0;
	op1 = get(i-1, k, dp);
	if(i-k >= 0)	op2 = get(i-k, k, dp);

	return dp[i] = (op1 + op2) % mod;
}

void precompute(vector<int> &dp, int n, int k)
{
	for(int i = 0; i < n; i++)
	{
		dp[i] = get(i, k, dp);
	}

	for(int i = 1; i < n; i++)
	{
		dp[i] += dp[i-1];
		dp[i] = dp[i] % mod;
	}
}

void solve()
{
	int k, t;
	cin >> t >> k;
	vector<int> dp(100005, -1);
	precompute(dp, 100005, k);
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		cout<<(dp[b] - dp[a-1] + mod) % mod<<endl;
	}

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