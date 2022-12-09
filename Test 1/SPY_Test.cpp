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
	multiset<int> s;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++)
	{
		if(s.find(a[i]) == s.end())	continue;
		int e = a[i];
		// if(a[i] == 0)
		// {
		// 	s.erase(0);
		// 	if(s.find(0) == s.end())
		// 	{
		// 		cout<<"NO";
		// 		return;
		// 	}
		// 	else
		// 	{
		// 		s.erase(0);
		// 	}
		// }
		// else
		 if(s.find(2*a[i]) != s.end())
		{
			s.erase(2*a[i]);
			s.erase(a[i]);
		}
		else if(s.find(a[i]/2) != s.end())
		{
			s.erase(a[i]/2);
			s.erase(a[i]);
		}
		else
		{
			cout<<"NO";
			return;
		}
	}
	cout<<"YES";

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