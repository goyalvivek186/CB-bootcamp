#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> m;
	set<int> s;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
		s.insert(a[i]);
	}
	sort(a.begin(), a.end());
	int ans = 0;
	int cnt = 0;
	for(int i = n-1; i >= 0; i--)
	{
		if(m[a[i]] > 1)
		{
			cnt = 0;
			int e = a[i];
			while(s.find(e) != s.end())
			{
				e++;
				cnt++;
			}
			ans += cnt;
			m[a[i]]--;
			s.insert(e);
		}
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