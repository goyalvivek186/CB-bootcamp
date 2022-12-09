#include <iostream>
#include <vector>
// #include <string>
#include <algorithm>
// #include <set>
// #include <climits>

#define int long long

// #define mod 1000000007

using namespace std;


void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	int i, j, k;
	j = n-1;
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			int x = a[i];
			int z = a[j];
			int y = z+x;
			int ind = lower_bound(a.begin()+j+1, a.end(), y) - a.begin();
			// if(ind == n)	continue;
			s += ind-j-1;
			// cout<<i<<" "<<j<<" "<<ind<<endl;
			
		}

	}
	cout<<s;
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