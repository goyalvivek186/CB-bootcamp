#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
#include <queue>
// #include <climits>

#define int long long

using namespace std;

class compare
{
public:
	bool operator()(pair<string, int>p1, pair<string, int> p2)
	{
		return p1.second < p2.second;
	}
};

void solve()
{
	int n;
	cin >> n;
	unordered_map<string, int> m;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m[s] = i;
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
    for(pair<string, int> p : m)
    {
        pq.push(p);
    }
    while(!pq.empty())
    {
        cout<<pq.top().first<<endl;
        pq.pop();
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