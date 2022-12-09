#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;


void get(int a, int b, int cur, int &ans)
{
	if(a == 1 and b == 1)
	{
		ans = min(ans, cur);
		return;
	}
	if(a - b > 0)
	{
		get(a-b, b, cur+1, ans);
	}
	if(b - a > 0)
	{
		get(a, b-a, cur+1, ans);
	}
}

void solve()
{
	int n;	cin >> n;
	if(n == 1)
	{
		cout<<"0";
		return;
	}
	int ans = INT_MAX;
	for(int i = 1; i < n; i++)
	{
		get(i, n-i, 1, ans);
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
	}

	return 0;
}