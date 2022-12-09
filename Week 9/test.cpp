#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	cout<<*(s.end());

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