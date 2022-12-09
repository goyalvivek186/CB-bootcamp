#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
// #include <climits>

#define int long long

#define mod 1000000007

using namespace std;


void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
            int comb = pow(2,j-i-1);
            ans += comb * (a[j] - a[i]);
			ans = ans % mod;
		}
	}

	cout<<ans;
}
int32_t main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}