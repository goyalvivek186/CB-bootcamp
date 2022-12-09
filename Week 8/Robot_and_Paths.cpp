#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
// #include <climits>

#define int long long

using namespace std;

int get(int dp[][1001], int i, int j, char a[][1001])
{
    if(i < 0 or j < 0)      return 0;
	if(i == 0 and j == 0)	return 1;
	if(a[i][j] == '#')	return 0;
	if(dp[i][j] != -1)	return dp[i][j];
	int op1, op2;
	op1 = op2 = 0;
	if(i-1 >= 0)	op1 = get(dp, i-1, j, a);
	if(j-1 >= 0)	op2 = get(dp, i, j-1, a);
	int ans = op1 % 1000000007 + op2 % 1000000007;
	return dp[i][j] = ans % 1000000007;
}


void solve()
{
	int m, n;
	cin >> m >> n;
	char a[1001][1001];
	int k;
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x-1][y-1] = '#';
	}
	if(a[0][0] == '#' or a[m-1][n-1] == '#')
	{
		cout<<"0";
		return;
	}
	
	int dp[1001][1001];
	memset(dp, -1, sizeof(dp));
	int ans= get(dp, m-1, n-1, a);
	cout<<(ans % 1000000007);
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