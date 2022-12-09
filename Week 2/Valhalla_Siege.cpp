#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define int long long

using namespace std;

void print_array(int *a, int n)
{
	for(int i = 0; i < n; i++)	cout<<a[i]<<"\t";
	cout<<endl;
}

void solve()
{
	int n, q;	cin >> n >> q;
	int a[n] = {0};
	int k[q] = {0};
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] += sum;
		sum = a[i];
	}
	sum = 0;
	for(int i = 0; i < q; i++)
	{
		cin >> k[i];
	}

	// print_array(a, n);
	// print_array(k, q);

	int kill = 0;
	int strength = 0;
	for(int i = 0; i < q; i++)
	{
		strength += k[i];
		kill = upper_bound(a, a + n, strength) - a;
		if(kill == n)
		{
			kill = n;
			strength = 0;
		}
		else
		{
			// die = kill;
			kill = n-kill;
		}
		cout<<kill<<endl;
	}

}

int32_t main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}
