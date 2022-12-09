#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#define ll long long

using namespace std;

void solve()
{
	string a;
	cin >> a;
	stack<char> s;
	for(int i = a.size()-1; i >= 0; i--)
	{
		char ch = a[i];
		if(s.empty() or s.top() != ch)
		{
			s.push(ch);
		}
		else if(s.top() == ch)
		{
			s.pop();
		}
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}

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