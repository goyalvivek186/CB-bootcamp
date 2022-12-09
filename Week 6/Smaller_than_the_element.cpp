#include <iostream>
#include <vector>
// #include <string>
// #include <algorithm>
// #include <climits>
#include <set>
#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	// vector<int> v(n, 0);
	// for(int i = 0; i < n; i++)	cin >> v[i];
	set<int> s;
	s.insert(-1);
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.insert(x);
		auto it = s.lower_bound(x);
		it--;
		cout<<(*it)<<endl;
	}

}

int32_t main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}