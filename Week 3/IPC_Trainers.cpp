#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#define ll long long

using namespace std;

void solve()
{
	int n, days;	cin >> n >> days;
	vector<int> d(n, 0);
	vector<int> t(n, 0);
	vector<int> s(n, 0);
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; i++)
	{
		cin >> d[i] >> t[i] >> s[i];
		pq.push(make_pair(s[i], i));
	}
	set<int> check;
	for(int i = 1; i <= days; i++)	check.insert(i);
	ll ans = 0;
	while(! pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();
		int start = d[p.second];
		int day = t[p.second];
		int sad = p.first;
		// cout<<start<<" "<<day<<" "<<sad<<endl;
		// int cnt = 0;
		int i = start;
		while(i <= days and day > 0)
		{
			// cout<<i<<" ";
			auto f = check.lower_bound(i);
			if(f == check.end())
			{
				break;
			}
			else
			{
				check.erase(f);
				day--;
			}

			i++;



			// if(check.find(i) != check.end())
			// {
			// 	check.erase(i);
			// 	day--;
			// }
			// i++;
		}
		if(day > 0)
		{
			ans += day * sad;
		}
	}
	// for(auto it = check.begin(); it != check.end(); it++)
	// {
	// 	cout<<*it<<" ";
	// }
	cout<<ans<<endl;

}

int main()
{
	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}