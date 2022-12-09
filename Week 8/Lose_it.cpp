#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <list>
// #include <climits>

#define int long long

using namespace std;
//4,8,15,16,23,42
void solve()
{
	int n;
	cin >> n;
	vector<int> a(6);
	a[0] = 4, a[1] = 8, a[2] = 15, a[3] = 16, a[4] = 23, a[5] = 42;
	unordered_map<int, list<int>> m;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[x].push_back(i);
        // cout<<i<<"\t"<<x<<endl;
	}

	// int cnt = 0, ind = -1, cur = 0;
	int cnt = 0, ind = -1, cur = 0, ans = 0;
	while(cnt <= n)
	{
		// int ans = 0;
		cur = 0;
		ind = -1;
		bool q = false;
		for(int i = 0; i < 6; i++)
		{
			if(m.count(a[i]) == 0 or m[a[i]].size() == 0)
			{
				q = true;
				break;
			}
			int x = *m[a[i]].begin();
			while(x < ind and m[a[i]].size() > 1)
			{
				ans++;
				m[a[i]].pop_front();
				if(m[a[i]].size() == 0)
				{
					q = true;
					break;
				}
				x = *m[a[i]].begin();
			}
			if(q or ind > x)	break;
			else
			{
				ind = x;
				m[a[i]].pop_front();
				cur++;
			}
            // cout<<ind<<" ";
		}
		if(q or cur < 6)	break;
		cnt += cur;
	}
    // cout<<endl;
	cout<<n - cnt;

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