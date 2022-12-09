#include <iostream>
// #include <vector>
#include <string>
// #include <algorithm>
#include <set>
#include <ctype.h>
// #include <climits>

#define int long long

using namespace std;

void get(string s, set<string> &st, string cur, int i)
{
	if(i == s.length())
	{
		st.insert(cur);
		return;
	}
	if(isdigit(s[i]))
	{
		cur.push_back(s[i]);
		get(s, st, cur, i+1);
	}
	else
	{
		cur.push_back(s[i]);
		get(s, st, cur, i+1);
		cur.pop_back();
		if(isupper(s[i]))
		{
			cur.push_back(tolower(s[i]));
		}
		else
		{
			cur.push_back(toupper(s[i]));
		}
		get(s, st, cur, i+1);
	}
}

void solve()
{
	string s;
	cin >> s;
	set<string> st;
	string cur;
	get(s, st, cur, 0);
	for(auto it = st.begin(); it != st.end(); it++)
	{
		cout<<(*it)<<" ";
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