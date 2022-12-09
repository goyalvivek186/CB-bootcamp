#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	map<string, int> m;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if(m.find(s) == m.end())
		{
			cout<<"OK"<<endl;
			m[s] = 1;
		}
		else
		{
			cout<<s<<m[s]<<endl;
			m[s]++;
		}
	}

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