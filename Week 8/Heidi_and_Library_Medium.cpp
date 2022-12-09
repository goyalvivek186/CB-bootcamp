#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <list>
// #include <queue>
// #include <climits>

#define int long long

using namespace std;


void solve()
{
	int n, k;	cin >> n >> k;
	vector<int> a(n, 0);
	unordered_map<int, list<int>> m;
	unordered_set<int> s;
	set<pair<int, int>, greater<pair<int, int>>> pq;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]].push_back(i);
	}

	if(k >= n)
	{
		cout<<m.size();
		return;
	}

	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		if(s.size() < k)
		{
			if(s.find(a[i]) == s.end())
			{
				cnt++;
				if(m[a[i]].size() > 1)
				{
					s.insert(a[i]);
					m[a[i]].pop_front();
					pq.insert({(*m[a[i]].begin()), a[i]});
				}
			}
		}
		else
		{
			if(s.find(a[i]) == s.end())
			{
				while(s.size() >= k)
				{
                    pair<int, int> p = *pq.begin();
					s.erase(p.second);
                    // s.erase(*pq.begin().second)
					pq.erase(pq.begin());
				}

				cnt++;
				if(m[a[i]].size() > 1)
				{
					s.insert(a[i]);
					m[a[i]].pop_front();
					pq.insert({(*m[a[i]].begin()), a[i]});
				}

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
	cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}