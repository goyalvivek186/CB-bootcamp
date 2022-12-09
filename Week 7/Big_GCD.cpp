#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

int gcd(int a, int b)
{
	if(b == 0)	return a;

	return gcd(b, a%b);	
}

void solve()
{
	int a;
	string s;
	cin >> a >> s;
	if(a == 0)
	{
		cout<<s;
		exit(0);
	}
	int b = 0;
	for(int i = 0; i < s.length(); i++)
	{
		b = (b * 10) + (s[i] - '0');
        // cout<<b<<" ";
		b = b % a;
        // cout<<b<<endl;
	}
    // b = b + a;
	// cout<<b;
	cout<<gcd(b, a);

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