#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int a, b, t;
	cin >> a >> b >> t;
	vector<int> v(a*b, 0);
	int n = a*b;
	v[0] = 0;
	for(int i = 1; i < n; i++)
	{
		if((i%a)%b != (i%b)%a)	v[i]++;
		v[i] += v[i-1];
		// cout<<v[i]<<" ";
	}
	// cout<<endl;

	while(t--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		int x1 = l / n;
		int y1 = l % n;

		int x2 = r / n;
		int y2 = r % n;

		int cnt1 = 0, cnt2 = 0;
		cnt2 = x2 * v[n-1] + v[y2];
		cnt1 = x1 * v[n-1] + v[y1];
		cout<<cnt2 - cnt1<<" ";
	}
	

}

int32_t main()
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