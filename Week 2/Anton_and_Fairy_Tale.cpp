#include <iostream>
#include <vector>
#include <string>

#define int long long

using namespace std;

bool check(int m, int n, int x)
{
	if((m*(m+1))/2 >= n-x)	return true;
	return false;
}

int32_t main()
{
	int n, x;	cin >> n >> x;
	if(x >= n)
	{
		cout<<n;
		return 0;
	}
	int s = 0, e = 2e9;
	int ans = -1;
	while(s <= e)
	{
		int m = (s+e)/2;
		if(check(m, n, x))
		{
			ans = m;
			// cout<<ans<<endl;
			e = m-1;
		}
		else
		{
			s = m+1;
		}
	}
	if(ans != -1)	ans += x;
	cout<<ans;


	return 0;
}