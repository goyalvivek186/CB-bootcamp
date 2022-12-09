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
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
    if(n <= 1)
    {
        cout<<"Yes";
        return;
    }
	vector<int> l(n, 0);
	l[n-1] = a[n-1];

	for(int i = n-2; i >= 0; i--)
	{
		l[i] = min(a[i], l[i+1]);
	}

	for(int i = 0; i < n; i++)
	{
		if(a[i] - l[i] > 1)
		{
			cout<<"No";
			return;
		}
	}
	
	cout<<"Yes";

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