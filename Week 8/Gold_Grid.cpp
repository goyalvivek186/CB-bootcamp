#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void print_matrix(int a[][1001], int r, int c)
{
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}	
}

void solve()
{
	int n, m;
	cin >> n >> m;
	int a[1001][1001] = {0};
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x-1][y-1]++;
	}
	// print_matrix(a, n, n);
	// cout<<endl;

	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			a[i][j] = a[i][j] + a[i][j-1];
		}
	}

	// print_matrix(a, n, n);
	// cout<<endl;

	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			a[j][i] = a[j][i] + a[j-1][i];
		}
	}

	// print_matrix(a, n, n);
	int ans = 0;
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-1; j++)
		{
			int op1, op2, op3, op4;
			op1 = a[i][j];
			op2 = a[i][n-1] - op1;
			op3 = a[n-1][j] - op1;
			op4 = a[n-1][n-1] - op2 - op3 - op1;
			ans = max(ans, min({op1, op2, op3, op4}));
		}
	}
	cout<<ans;

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