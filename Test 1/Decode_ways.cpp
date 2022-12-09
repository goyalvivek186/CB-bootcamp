#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
// #include <climits>

#define int long long
#define mod 1000000007

using namespace std;

void get(string s, int i, set<string> &st, string cur)
{
	if(i == s.length())
	{
		st.insert(cur);
        // cout<<cur<<endl;
		return;
	}
	int x = s[i] - '0';
	// cout<<x<<endl;
	char e = s[i] - '0' + 'A' - 1;
	// cout<<e<<endl;
	if(x > 0)
	{
		cur.push_back(e);
		get(s, i+1, st, cur);
		cur.pop_back();
	}
	if(x > 0 and i+1 < s.length())
	{
		int y = s[i+1] - '0';
		x = x*10 + y;
		if(x >= 10 and x <= 26)
		{
            // cout<<x<<endl;
			char ch = x + 'A' - 1;
			cur.push_back(ch);
			get(s, i+2, st, cur);
			cur.pop_back();
		}
	}
	

}

void solve()
{
	string s;
	cin >> s;
	set<string> st;
	string cur;
	get(s, 0, st, cur);
	cout<<st.size() % mod;
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