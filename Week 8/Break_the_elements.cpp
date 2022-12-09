#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	int odd, even;
	odd = even = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if(x & 1 == 1)	odd++;
		else			even++;
	}
	if(odd == 0 or even == 0)
	{
		cout<<"0";
		return;
	}
	else
	{
		cout<<even;
		return;
	}

}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}