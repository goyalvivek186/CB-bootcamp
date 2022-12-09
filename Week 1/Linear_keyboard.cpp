#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int a[26] = {0};
		int x = 0;
		for(char ch : s1)
		{
			a[ch - 'a'] = x;
			x++;
		}

		int ans = 0;
		int p = a[s2[0] - 'a'];
		for(char ch : s2)
		{
			int c = a[ch - 'a'];
			ans += abs(c - p);
			p = c;
		}
		cout<<ans<<endl;
	}
	



	return 0;
}