#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n, t;
	cin >> n >> t;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	
	int cur = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0 and cur < 0)
		{
			//check the balence to be non-neg
			cur = 0;
		}
		else if(a[i] > 0)
		{
			//deposit
			cur += a[i];
			if(cur > t)
			{
				cout<<"-1";
				return;
			}

		}
		else if(a[i] < 0)
		{
			//withdraw
			cur += a[i];
		}
	}
	//answer exist
	cur = 0;
	ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0 and cur < 0)
		{
			cur = t;
			ans++;
		}
		else
		{
			cur += a[i];
			if(cur > t)	cur = t;
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

		// cout<<endl;
	}

	return 0;
}