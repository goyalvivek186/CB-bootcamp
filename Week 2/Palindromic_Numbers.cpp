#include <iostream>
#include <vector>
#include <string>
// #include <cstring>
#define int long long

using namespace std;

int32_t main()
{
	int t;	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s(n, '0');
		// s.resize(n);
		for(int i = 0; i < n; i++)
		{
			char ch;
			cin >> ch;
			s[i] = '9' - ch;
			// cout<<s[i];
		}
		cout<<s<<endl;
		
	}
	



	return 0;
}