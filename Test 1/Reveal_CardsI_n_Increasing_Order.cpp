#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	queue<int> q;
	vector<int> ans(n);
	for(int i = 0; i < n; i++)	q.push(i);
	for(int i = 0; i < n; i++)
	{
		ans[q.front()] = a[i];
		q.pop();
		q.push(q.front());
		q.pop();
	}
	for(int i = 0; i < n; i++)	cout<<ans[i]<<" ";

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