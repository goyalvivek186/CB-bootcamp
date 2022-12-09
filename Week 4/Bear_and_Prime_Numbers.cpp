#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
const int N = 1000009;
#define int long long

using namespace std;

vector<int> primes_seive()
{
	// int N = 10000009;
	int *a = new int[N]{0};
	for(int i = 3; i < N; i += 2)
	{
		a[i] = 1;
	}
	for(int i = 3; i < N; i++)
	{
		if(a[i] == 1)
		{
			for(int j = i*i; j < N; j += i)
			{
				a[j] = 0;
			}
		}
	}
	vector<int> primes;
	primes.push_back(2);
	for(int i = 3; i < N; i++)
	{
		if(a[i] == 1)	primes.push_back(i);
	}
	return primes;
}

vector<int> create_segment(vector<int> &primes, int mn, int mx)
{
	vector<int> segment;
	int a[mx - mn + 1] = {0};
	memset(a, 1, sizeof(a));
	for(int i = 0; primes[i] * primes[i] <= mx; i++)
	{

		int start = lower_bound(primes.begin(), primes.end(), i) - primes.begin();
		for(int j = start; j*j <= mx; j+= primes[i])
		{
			a[j] = 0;
		}
		if(primes[start] == i)	a[start] = 1;
	}
	for(int i = 0; i < mx - mn + 1; i++)
	{
		if(a[i] == 1)
		{
			segment.push_back(i+mn);
		}
	}
	return segment;
}


void solve()
{
	vector<int> primes = primes_seive();
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	int m;
	cin >> m;
	vector<pair<int, int>> p;
	int mx = INT_MIN;
	int mn = INT_MAX;
	for(int i = 0; i < m; i++)
	{
		int x, y;	cin >> x >> y;
		p.push_back({x, y});
		mx = max(mx, y);
		mn = min(mn, x);
	}
	int ans = 0;
	if(mx < N)
	{
		for(int i = 0; i < m; i++)
		{
			ans = 0;
			int x = p[i].first;
			int y = p[i].second;
			int ind = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
			for(int j = ind; primes[j] <= y; j++)
			{
				int ind = lower_bound(a.begin(), a.end(), primes[j]) - a.begin();
				for(int k = ind; k < n; k++)
				{
					if(a[k] % primes[j] == 0)	ans++;
				}
			}
			cout<<ans<<endl;
		}
		
	}
	else
	{
		// cout<<"Out of Scope"<<endl;
		vector<int> segment = create_segment(primes, mn, mx);
		for(int i = 0; i < m; i++)
		{
			ans = 0;
			int x = p[i].first;
			int y = p[i].second;
			int ind = lower_bound(segment.begin(), segment.end(), x) - segment.begin();
			for(int j = ind; segment[j] <= y; j++)
			{
				int ind = lower_bound(a.begin(), a.end(), segment[j]) - a.begin();
				for(int k = ind; k < n; k++)
				{
					if(a[k] % segment[j] == 0)	ans++;
				}
			}
			cout<<ans<<endl;
		}
	}

}

int32_t main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}