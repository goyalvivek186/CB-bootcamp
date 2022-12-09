#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>

#define int long long

using namespace std;

int get(vector<int> &a, int n, int l)
{
	int m = max(a[0], l-a[n-1]) * 2;
	for(int i = 1; i < n; i++)
	{
		m = max(m, a[i] - a[i-1]);
	}
	return m;
}



void solve()
{
	int n,l;	cin >> n >> l;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	cout<<setprecision(9)<<(get(a, n, l) / 2.0);

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