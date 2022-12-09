#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <list>
#define ll long long

using namespace std;

template<typename t>
class graph
{
public:
	map<t, list<t>> m;

	void add_edge(t a, t b, bool bi = true)
	{
		m[a].push_back(b);
		if(bi)	m[b].push_back(a);
	}

	void SSSP(t src)
	{
		map<t, int> dis;
		dis[src] = 0;
		queue<t> q;
		q.push(src);
		while(!q.empty())
		{
			t f = q.front();
			q.pop();
			for(t nbr : m[f])
			{
				if(dis.count(nbr) == 0)
				{
					dis[nbr] = dis[f] + 1;
					q.push(nbr);
				}
			}
		}

		for(auto it : dis)
		{
			cout<<src <<" to "<<it.first<<" -> "<<it.second<<endl;
		}
	}

	bol dfs_helper(t src, map<t, bool> &visited, t par)
	{
		visited[src] = true;
		for(t nbr : m[src])
		{
			if(visited[nbr] and nbr != par)
			{
				return true;
			}
		}

	}

	bool cycle_detection_DFS()
	{
		map<t, bool> visited;
		for(auto it : m)
		{
			if(dfs_helper(it.first, visited, -1))	return true;
		}
		return false;
	}


};

int main()
{
	int n;
	cin >> n;
	graph<int> g;
	while(n--)
	{
		int a, b;
		cin >> a >> b;
		g.add_edge(a, b);
	}
	g.SSSP(0);
	
	
	return 0;
}