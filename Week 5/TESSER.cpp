#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

bool check(int a, int b, char ch)
{
	if(ch == 'G')	return a < b;
	if(ch == 'L')	return a > b;
	if(ch == 'E')	return a == b;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	string s;
	cin >> s;
	int i = 0, j = 0;
	for(int it = 0; it < n-1; it++)
	{
		i = it;
		while(i < n-1 and j < s.size() and check(a[i], a[i+1], s[j]))
		{
			// cout<<i<<" "<<j<<endl;
			i++;
			j++;
		}
		if(j == s.length())
		{
			break;
		}
		else
		{
			j = 0;
		}
	}
	if(j == s.length())	cout<<"YES";
	else				cout<<"NO";
}

int main()
{
	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}