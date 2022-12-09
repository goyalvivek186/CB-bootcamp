#include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <climits>
#include <queue>
#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int> , greater<int>> pq;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}
	int ans = 0;
	while(pq.size() > 1)
	{
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		ans += x + y;
		pq.push(x+y);
	}
	cout<<ans;

}

int32_t main()
{
	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();

		cout<<endl;
	}

	return 0;
}