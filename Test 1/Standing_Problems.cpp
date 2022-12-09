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
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	int cur = 0;
	int ans = 0;
// A person will be disappointed if the time he waits is more 
// than the time needed to serve him
	for(int i = 0; i < n; i++)
	{
		if(a[i] < cur)	ans++;
		else cur += a[i];
	}
	cout<<n-ans;
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