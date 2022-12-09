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
	priority_queue<int> pq;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}
	bool ada = true;
	while(!pq.empty() and pq.top() > 1)
	{
		int x = pq.top();
		pq.pop();
		if(x & 1)	//odd
		{
			pq.push(x/2);
			pq.push(x/2 + 1);
		}
		else
		{
			pq.push(x/2);
			pq.push(x/2);
		}
		ada = ! ada;
	}

	if(!ada)
	{
		cout<<"Adarsh";
	}
	else
	{
		cout<<"Tushar";
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