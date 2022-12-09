#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#define ll long long

using namespace std;

void get(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> &pq, string s, int p)
{
	pair<int, string> x = pq.top();
	pq.pop();
	if(x.second == s)
	{
		pq.push(make_pair(p, s));
		return;
	}
	else
	{
		get(pq, s, p);
		pq.push(x);
	}
}


void solve()
{
	int n;	cin >> n;
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
	for(int i = 1; i <= n; i++)
	{
		int x;
		string s;
		int p;
		cin >> x;
		if(x == 1)
		{
			cin >> s;
			cin >> p;
			pq.push(make_pair(p, s));
		}
		else if(x == 2)
		{
			cin >> s;
			cin >> p;
			get(pq, s, p);
		}
		else if(x == 3)
		{
			cin >> s;
			cout<<pq.top().second<<" "<<i<<endl;
			pq.pop();
		}
	}

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