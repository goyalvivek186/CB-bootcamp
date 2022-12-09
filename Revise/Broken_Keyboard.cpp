#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	string s;
	cin >> s;
	int n = s.length();
	set<char> st;
	int a[26] = {0};
	for(int i = 0; i < n; i++)
	{
		char ch = s[i];
		int cnt = 1;
		int j = i+1;
		while(j < n and s[j] == s[i])
		{
			j++;
			cnt++;
		}
		i = j-1;
		if(cnt % 2 != 0)	a[ch-'a']++;
	}
	// for(auto it = st.begin(); it != st.end(); it++)
	// {
	// 	cout<<*it;
	// }
	for(int i = 0; i < 26; i++)
	{
		if(a[i] > 0)
		{
			char ch = i + 'a';
			cout<<ch;
		}
	}
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