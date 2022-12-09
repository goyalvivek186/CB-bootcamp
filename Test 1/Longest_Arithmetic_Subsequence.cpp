#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> s;
	for(int i = 0; i < n; i++)	cin >> a[i];
	set<int> st(a.begin(), a.end());
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
			s.insert(a[j] - a[i]);
	}
	vector<int> x;
	for(auto it  = s.begin(); it != s.end(); it++)
	{
		x.push_back(*it);
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < x.size(); j++)
		{
			int e = a[i];
			int d = x[j];
			if(d == 0)	continue;
			if(st.find(e - d) != st.end())	continue;
			int cnt = 0;
			while(st.find(e) != st.end())
			{
				// cout<<e<<" ";
				cnt++;
				e += d;
			}
			// cout<<e<<endl;
			ans = max(ans, cnt);
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