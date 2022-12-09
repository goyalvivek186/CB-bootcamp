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
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];

	vector<int> dp(n, 0);
	for(int i = 1; i < n; i++)
	{
		dp[i] = INT_MAX;
		for(int j = 1; j <= k; j++)
		{
			if(i-j < 0)	break;
			dp[i] = min(dp[i], dp[i-j] + abs(a[i-j] - a[i]));
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
	// cin >> t;
	while(t--)
	{
		solve();

		// cout<<endl;
	}

	return 0;
}