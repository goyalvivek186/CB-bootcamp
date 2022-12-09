#include <iostream>
#include <vector>
#include <string>

#define int long long

using namespace std;

bool check(int n, int m, int x, int y, int mid)
{
	int cou = m;
	int rem = n-mid;
	cou = cou + (rem * y);
	if(cou/x >= mid)	return true;
	return false;
}



int32_t main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	if(m/y >= n)
	{
		cout<<n;
		return 0;
	}
	int s = 0, e = n;
	int ans = -1;
	while(s <= e)
	{
		int mid = (s+e)/2;
		if(check(n, m, x, y, mid))
		{
			ans = mid;
			s = mid+1;
		}
		else
		{
			e= mid-1;
		}
	}
	cout<<ans;



	return 0;
}