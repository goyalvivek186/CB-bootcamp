#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

void solve()
{
	int n;	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int s = a[i];
		int e = a[i] + 5;
        
		int ind = upper_bound(a.begin(), a.end(), e) - a.begin();
        ans = max(ans, ind - i);
	}
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