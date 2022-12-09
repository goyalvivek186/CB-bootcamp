#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	unordered_set<string>m;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		m.insert(v[i]);
	}
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)
	{
		string s = v[i];
		for(int j = 1; j < s.length(); j++)
		{
			string x = s.substr(0, j);
			string y = s.substr(j, s.length() - j);
			// cout<<x<<" "<<y<<endl;
            if(m.find(x) != m.end() and m.find(y) != m.end())
            {
                a[i]++;
                break;
            }
		}
	}

    for(int i = 0; i < n; i++)  cout<<a[i];
	

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