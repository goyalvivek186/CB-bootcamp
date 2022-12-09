#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];

	vector<int> dp(n+1, INT_MAX);
	dp[0] = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(i-j >= 0)
			{
				dp[i] = min(dp[i], abs(a[i] - a[i-j]) + dp[i-j]);
			}
			else	break;
		}
	}
	cout<<dp[n-1];
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