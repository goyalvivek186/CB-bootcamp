#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;

bool compare(string a1, string a2)
{
	int s1, s2, h1, h2;
	s1 = s2 = h2 = h1 = 0;
	for(char ch : a1)
	{
		if(ch == 's')		s1++;
		else if(ch == 'h')	h1++;
	}

	for(char ch : a2)
	{
		if(ch == 's')		s2++;
		else if(ch == 'h')	h2++;
	}

	return s1*h2 > s2*h1;
}

void solve()
{
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end(), compare);

	int s = 0, h = 0, sh = 0, m = 0;
	for(int i = 0; i < n; i++)
	{
		s = 0, h = 0;
		for(char ch : a[i])
		{
			if(ch == 's')
			{
				s++;
			}
			else if(ch == 'h')
			{
				sh = sh + m + s;
			}
		}
		m += s;
	}
	cout<<sh;

}

int32_t main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}