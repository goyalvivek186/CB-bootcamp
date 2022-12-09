#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
// #include <climits>

#define int long long

using namespace std;

bool solve()
{
	string st;
	cin >> st;
	stack<char> s;
	if(st.length() < 2)	return false;
	for(int i = 0; i < st.length(); i++)
	{
		char ch = st[i];
		if(ch == 'B')
		{
			if(s.empty())	return false;
			s.pop();
		}
		else
		{
			s.push(ch);
		}
	}

	return true;
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
		bool ans = solve();
		if(ans)
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}

		//cout<<endl;
	}

	return 0;
}