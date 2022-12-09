#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<set>

#define ll long long

using namespace std;

bool check(string s)
{
	// cout<<s<<endl;
	if(s == "bear")	return true;
	return false;
}

void solve()
{
	string a;
	cin >> a;
	int n = a.length();
	if(n < 4)
	{
		cout<<"0";
		return;
	}
	set<pair<int, int>> s;
	for(int i = 0; i < n-3; i++)
	{
		if(check(a.substr(i, 4)))
		{
			if(i == 0)	//at start
			{
				// cout<<"start"<<endl;
				for(int j = 3; j < n; j++)
				{
					s.insert(make_pair(0, j));
					// cout<<"0"<<" "<<j<<endl;
				}
			}
			else if(i == n-4)	//at end
			{
				// cout<<"end"<<endl;
				for(int j = 0; j <= i; j++)
				{
					s.insert(make_pair(j, n-1));
					// cout<<j<<" "<<n-1<<endl;
				}
			}
			else	//in middle
			{
				// cout<<"mid"<<endl;
				for(int j = 0; j <= i; j++)
				{
					for(int k = i+3; k < n; k++)
						s.insert(make_pair(j, k));
				}
				for(int j = i+3; j < n; j++)
				{
					s.insert(make_pair(i, j));
				}
			}

		}
	}
	int cnt = 0;
	for(auto it = s.begin(); it != s.end(); it++)	cnt++;
	// {
	// 	int f = (*it).first;
	// 	int s = (*it).second;
	// 	cout<<f<<" "<<s<<endl;
	// 	cnt++;
	// }

	cout<<cnt;

}

int main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}