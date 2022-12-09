#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];

	vector<int> dp(n, 0);
	for(int i = 1; i < n; i++)
	{
		int op1, op2;
		op1 = op2 = INT_MAX;
		if(i-1 >= 0)
		{
			op1 = dp[i-1] + abs(a[i-1] - a[i]);
		}
		if(i-2 >= 0)
		{
			op2 = dp[i-2] + abs(a[i-2] - a[i]);
		}
		dp[i] = min(op1, op2);
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