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
	vector<int> a(n);
	int p = 1;
	bool z = false;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] != 0)	p *= a[i];
		else			z = true;
	}
	for(int i = 0; i < n; i++)
	{
		if(z)
		{
			if(a[i] == 0)	cout<<p<<" ";
			else			cout<<"0 ";
		}
		else
		{
			cout<<p/a[i]<<" ";
		}
	}

}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}