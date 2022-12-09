#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}
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
	int cum[n+1] = {0};
	for(int i = 0; i < n; i++)	cin >> a[i];
	for(int i = 0; i < n; i++)	cum[i+1] = cum[i] + a[i];

	print_vector(a);
	print_array(cum, n+1);


	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cum[i] == cum[n]-cum[i-1])
		{
			cout<<i-1<<" ";
			ans++;
			// cout<<i<<endl;
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