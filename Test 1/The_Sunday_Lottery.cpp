#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	string s;
	cin >> s;
	string st(s.begin(), s.end());
	sort(st.begin(), st.end(), greater<char>());
	// cout<<st;
	int i = 0, j = 0;
	while(i < s.length() and s[i] == st[j])		i++, j++;
	if(i == s.length())
	{
		cout<<s;
		return;
	}
	swap(s[i], st[j]);
	int k = s.length()-1;
	while(k > i and s[k] != s[i])	k--;
	s[k] = st[j];
	cout<<s;



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