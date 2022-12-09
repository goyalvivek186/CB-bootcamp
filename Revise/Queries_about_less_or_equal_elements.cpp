#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	int a[n] = {0}, b[m] = {0};
	for(int i = 0; i < n; i++)	cin >> a[i];
	for(int i = 0; i < m; i++)	cin >> b[i];
	sort(a, a+n);
	for(int i = 0; i < m; i++)
	{
		int ans = lower_bound(a, a+n, b[i]) - a;
		cout<<ans<<" ";
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