#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>

#define int long long

using namespace std;


void print_array(int *a, int n)
{
	for(int i = 0; i < n; i++)	cout<<a[i]<<" ";
	cout<<endl;
}

void solve()
{
	int m, n;
	cin >> m >> n;
	string p, s;
	cin >> p >> s;
	
	int l[n] = {0};
	int j = 0;
	for(int i = 0; i < m and j < n; i++)
	{
		if(p[i] == s[j])	l[j] = i, j++;
	}

	j = n-1;
	int r[n] = {0};
	for(int i = m-1; i >= 0 and j >= 0; i--)
	{
		if(p[i] == s[j])	r[j] = i, j--;
	}
	// print_array(l, n);
	// print_array(r, n);

	int ans = 1;
	for(int i = 1; i < n; i++)	ans = max(ans, r[i] - l[i-1]);

	cout << ans;

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