#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	vector<int> cumu(n+1, 0);
	for(int i = 0; i < n; i++)
	{
		cumu[i+1] = cumu[i] + a[i];
	}
	sort(a.begin(), a.end());
	vector<int> scumu(n+1, 0);
	for(int i = 0; i < n; i++)
	{
		scumu[i+1] = scumu[i] + a[i];
	}
	int m;	cin >> m;
	while(m--)
	{
		int x;	cin >> x;
		int l, r;
		cin >> l >> r;
		if(x == 1)
		{
			cout<<cumu[r] - cumu[l-1]<<endl;
		}
		if(x == 2)
		{
			cout<<scumu[r] - scumu[l-1]<<endl;
		}
	}

}

int32_t main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}