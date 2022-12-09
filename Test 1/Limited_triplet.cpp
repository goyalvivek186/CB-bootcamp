#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

int get(int i)
{
	return (i * (i-1))/2;
}

//doesn’t exceed K.
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int b = k+a[i];
		int ind = upper_bound(a.begin(), a.end(), b) - a.begin();
		ind--;
		if(ind - i < 2)	continue;
		// cout<<i<<" "<<ind-i<<" ";
		ans += get(ind - i);
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

		//cout<<endl;
	}

	return 0;
}