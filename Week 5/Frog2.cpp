#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define ll long long

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	vector<int> dp(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		dp[i] = INT_MAX;
		for(int j = 1; j <= k; j++)
		{
			if(i - j >= 0)
			{
				dp[i] = min(dp[i], dp[i-j] + abs(a[i] - a[i-j]));
			}
		}
	}
	cout<<dp[n-1];
}

int main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}