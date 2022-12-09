#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int m, n;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];
	// sort(a.begin(), a.end());
	int ans = n;
	for(int i = 0; i < n-1; i++)
	{
		ans += max(a[i], a[i+1]);
	}
	ans += max(a[n-1], a[0]);
	if(ans > m)	cout<<"NO";
	else		cout<<"YES";

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