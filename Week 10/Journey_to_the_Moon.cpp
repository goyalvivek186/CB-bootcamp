#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <list>
// #include <climits>

#define int long long

using namespace std;

class graph
{
public:
	map<int, list<int>> m;

	void add_edge(int a, int b)
	{
		m[a].push_back(b);
		m[b].push_back(a);
	}

	void dfs_helper(int src, int &cnt, map<int, bool> &visited)
	{
		cnt++;
		visited[src] = true;
		for(int des : m[src])
		{
			if(visited[des] == false)
			{
				dfs_helper(des, cnt, visited);
			}
		}
	}

	vector<int> get_components()
	{
		map<int, bool> visited;
		for(auto it : m)
		{
			visited[it.first] = false;
		}
		vector<int> com;
		for(auto it : m)
		{
			int cnt = 0;
			if(visited[it.first] == false)
			{
				dfs_helper(it.first, cnt, visited);
				com.push_back(cnt);
			}
		}
		return com;
	}
};

void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}

void solve()
{
	int m, n;
	cin >> m >> n;
	graph g;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g.add_edge(a, b);
	}

	vector<int> components = g.get_components();
	// print_vector(components);
	int total = (m*(m-1))/2;
	

	

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