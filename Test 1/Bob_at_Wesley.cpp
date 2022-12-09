#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
// #include <climits>

#define int long long

using namespace std;

void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	// cout<<endl;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	priority_queue<int, vector<int> , greater<int>> pq;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		pq.push(a[i]);
	}
	int i = 1;
	while(i < n)
	{
		a[i] = pq.top();
		pq.pop();
		i += 2;
	}
	i = 0;
	while(i < n)
	{
		a[i] = pq.top();
		pq.pop();
		i += 2;
	}
	int ans = 0;
	for(int i = 1; i < n-1; i++)
	{
		if(a[i] < a[i-1] and a[i] < a[i+1])	ans++;
	}

	cout<<ans<<endl;
	print_vector(a);

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