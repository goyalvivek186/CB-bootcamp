#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

int gcd(int a, int b)
{
	if(b == 0)	return a;

	return gcd(b, a%b);	
}


void solve()
{
	int a, b;
	cin >> a >> b;
	int ans = 0;
	if(a > b)	ans = gcd(a, b);
	else		ans = gcd(b, a);
	cout<<ans;

}

int main()
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