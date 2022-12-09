#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

int pow(int a, int b)
{
	if(b == 0)	return 0;
	int ans = 1;
	while(b > 0)
	{
		if(b & 1 == 1)	ans *= a;
		a = a*a;
		b = b >> 1;
	}
	return ans;
}

void solve()
{
	int a, b;
	cin >> a >> b;
	//a^b
	cout<<pow(a, b);
	

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