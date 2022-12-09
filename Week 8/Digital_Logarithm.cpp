#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
// #include <climits>

#define int long long

using namespace std;

int count(int e)
{
	int cnt = 0;
	while(e > 0)
	{
		cnt++;
		e = e/10;
	}
	return cnt;
}


void solve()
{
	int n;
	cin >> n;

	vector<int> v1(n, 0);
	multiset<int, greater<int>> a, b;
	for(int i = 0; i < n; i++)
	{
		cin >> v1[i];
		a.insert(v1[i]);
	}
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if(a.find(x) == a.end())
		{
			b.insert(x);
		}
		else
		{
			a.erase(a.find(x));
		}
	}

	int ans = 0;
	while(!a.empty() and !b.empty())
	{
		ans++;
		auto it1 = a.begin();
		auto it2 = b.begin();
		
		int x = *it1;
		int y = *it2;
		
		if(x > y)
		{
			int ans = count(x);
			if(b.find(ans) == b.end())
			{
				a.erase(it1);
				a.insert(ans);
			}
			else
			{
				a.erase(it1);
				b.erase(b.find(ans));
			}
		}
		else
		{
			int ans = count(y);
			if(a.find(ans) == a.end())
			{
				b.erase(it2);
				b.insert(ans);
			}
			else
			{
				b.erase(it2);
				a.erase(a.find(ans));
			}
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
	cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}