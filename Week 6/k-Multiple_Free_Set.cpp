#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++)	cin >> v[i];
	multiset<int> s;
	int ans = 0;
	int j = 0;
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++)
	{
		int op1 = v[i] * k;
		int op2;
		(v[i] % k == 0) ? op2 = v[i]/k : op2 = -1;
		if(s.find(op1) == s.end() and s.find(op2) == s.end())
		{
			s.insert(v[i]);
			ans = max(ans, (int)s.size());
		}
		
	}
	cout<<ans;

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