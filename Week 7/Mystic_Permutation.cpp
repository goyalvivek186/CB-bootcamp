#include <iostream>
#include <vector>
// #include<queue>
// #include <string>
// #include <algorithm>
#include <set>
// #include <climits>

#define int long long

using namespace std;

void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	// cout<<endl;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	set<int> s;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		auto it = s.begin();
		int x = *it;
		if(a[i] == x)
		{
			if(i == n-1)	
			{
				a[i] = x;
				s.erase(it);
				swap(a[i], a[i-1]);
			}
			else
			{
				a[i] = x + 1;
				s.erase(s.find(a[i]));
			}
		}
		else
		{
			a[i] = x;
			s.erase(it);
		}
	}
	print_vector(a);

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