#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<int> cur;
	for(int i = 0; i < n; i++)
	{
		if(cur.size() == 0)
		{
			cur.push_back(a[i]);
		}
		else
		{
			if(cur[cur.size()-1] + 1 == a[i])
			{
				cur.push_back(a[i]);
			}
			else
			{
				if(cur.size() == 1)
				{
					cout<<cur[0]<<endl;
					cur[0] = a[i];
				}
				else
				{
					cout<<cur[0]<<"->"<<cur[cur.size()-1]<<endl;
					cur.clear();
					cur.push_back(a[i]);
				}
			}
		}
	}
	if(cur.size() != 0)
	{
		if(cur.size() == 1)	cout<<cur[0]<<endl;
		else	cout<<cur[0]<<"->"<<cur[cur.size()-1]<<endl;
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