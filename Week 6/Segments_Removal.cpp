#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	int i = 0;
	while(i < n)
	{
		int e = a[i];
		if(i+1 < n and a[i+1] == e)
		{
			while(i < n and a[i] == e)	i++;
		}
		else
		{
			i++;
		}
		ans++;
	}
	cout<<ans;

}

int32_t main()
{
	int t = 4;	
	//cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}