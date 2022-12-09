#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
// #include <climits>

#define int long long

using namespace std;

void check(unordered_set<char> & s, char ch, char p)
{
	if(ch != '.' and ch != p and s.find(ch) == s.end())
	{
		s.insert(ch);
	}
}

void solve()
{
	int m, n;
	char ch;
	cin >> m >> n >> ch;
	char a[101][101];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)	cin >> a[i][j];

	unordered_set<char> s;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] == ch)
			{
				if(i-1 >= 0)
				{
					check(s, a[i-1][j], ch);
					
				}
				if(i + 1 < m)
				{
					check(s, a[i+1][j], ch);
				}
				if(j + 1 < n)
				{
					check(s, a[i][j+1], ch);
				}
				if(j - 1 >= 0)
				{
					check(s, a[i][j-1], ch);
				}
			}
		}
	}
	cout<<s.size();

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