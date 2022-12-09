#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[x]++;
		if(m[x] > 1)
		{
			cout<<x;
			return;
		}
	}

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