#include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <climits>

#define ll long long

using namespace std;

bool get(int a[][5], int n, bool f, int i, int p, int cur, int &ans)
{
	if(p < -2 or p > 2)	return false;
	if(i < 0)
	{
		ans = max(ans, cur);
		return true;
	}
	int j = p + 2;
	if(a[i][j] == 0 or a[i][j] == 1)
	{
		cur += a[i][j];
	}
	else
	{
		if(f)
		{
			f = false;
		}
		else
		{
			cur += a[i][j];
		}
	}

	//leftup
	get(a, n, f, i-1, p-1, cur, ans);
	//up
	get(a, n, f, i-1, p, cur, ans);
	//rightup
	get(a, n, f, i-1, p+1, cur, ans);
	return true;

}


void solve()
{
	int n = 5;
	int m;	cin >> m;
	int a[m][5] = {0};
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)	cin >> a[i][j];
	}
	
	int ans = 0;
	int cur = 0;
	int p = 0;
	bool first = true;
	get(a, m, first, m-1, p, cur, ans);
	get(a, m, first, m-1, p-1, cur, ans);
	get(a, m, first, m-1, p+1, cur, ans);
	cout<<ans;
}

int main()
{
	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}