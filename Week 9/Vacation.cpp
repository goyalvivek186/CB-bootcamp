#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int> > a;
	for(int i = 0; i < n; i++)
	{
		vector<int> x(3);
		for(int j = 0; j < 3; j++)
		{
			cin >> x[j];
		}
		a.push_back(x);
	}

	vector<vector<int>> dp(n, vector<int> (3));
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];

	for(int i = 1; i < n; i++)
	{
		dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = a[i][2] + max(dp[i-1][1], dp[i-1][0]);
	} 
	cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

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