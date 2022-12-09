#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void print_array(int *a, int n)
{
	for(int i = 0; i < n; i++)	cout<<a[i]<<" ";
	cout<<endl;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int l[n+1] = {0}, r[n+1] = {0};
	for(int i = 0; i < n; i++)	cin >> a[i];
	l[0] = 0;
	r[n] = 0;
	for(int i = 1; i <= n; i++)		l[i] = l[i-1] + a[i-1];
	for(int i = n-1; i >= 0; i--)	r[i] = r[i+1] + a[i];
	int ans = 0;
	
	// print_array(l, n+1);
	// print_array(r, n+1);
	for(int i = 0; i < n; i++)
	{
		if(l[i] == r[i+1])
		{
			cout<<i<<" ";
			ans++;
		}
	}

	if(ans == 0)	cout<<"-1";

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