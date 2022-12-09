#include <iostream>
#include <vector>
#include <string>

#define int long long

using namespace std;

bool check(int m, int n, int k)
{
	// if(((k*(k-1))/2)+1 < n)
	// {
	// 	// cout<<"-1";
	// 	return false;
	// }
	// return true;

	int mx = (k*(k+1))/ 2;
	int cur = (m*(m+1))/2;
	if(mx - cur - (k-m) + 1 >= n)	return true;
	else				return false;


}


int32_t main()
{
	int n, k;	cin >> n >> k;
	int s = 1, e = k;
	if(((k*(k-1))/2 +1) < n)
	{
		cout<<"-1";
		return 0;
	}
	int ans = -1;
	int x = 0;
	while(s <= e)
	{
		int m = (s+e)/2;
		if(check(m, n, k))
		{
			ans = m;
			x = s;
			s = m+1;
		}
		else
		{
			e = m-1;
		}
	}
	cout<<k-ans;


	return 0;
}