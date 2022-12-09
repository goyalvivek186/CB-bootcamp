#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
// #include <climits>

#define int long long

using namespace std;

int check(vector<int> &a, int i, unordered_set<int> s)
{
	for(; i < a.size(); i++)
	{
		if(s.size() == 1)	return *s.begin();
		if(s.find(a[i]) != s.end())	s.erase(a[i]);
	}
	return *s.begin();
}


void solve()
{
	int n, k;	cin >> n >> k;
	vector<int> a(n, 0);
	unordered_set<int> s;
	for(int i = 0; i < n; i++)	cin >> a[i];
	
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(s.size() < k)
		{
			if(s.find(a[i]) == s.end())
			{
				s.insert(a[i]);
				cnt++;
			}
		}
		else
		{
			if(s.find(a[i]) == s.end())
			{
				while(s.size() >= k)
				{
					int x = check(a, i, s);
					s.erase(x);
				}
				cnt++;
				s.insert(a[i]);
			}
			
		}
	}
	cout<<cnt;

}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	// cin >> t;
	while(t--)
	{
		solve();

		// cout<<endl;
	}

	return 0;
}