#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n, p, k;
	cin >> n >> p >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];

	sort(a.begin(), a.end());
	vector<int> dp(n+1, 0);
	for(int i = 0; i < n; i++)
	{
		if(i < k-1)
		{
			dp[i] = a[i] + ((i == 0) ? 0 : dp[i-1]);
		}
		else if(i == k-1)
		{
			dp[i] = a[i];
		}
		else
		{
			dp[i] = a[i] + dp[i-k];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(dp[i] <= p)	ans = i+1;
	}
	cout<<ans;
	

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