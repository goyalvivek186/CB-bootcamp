#include <iostream>
// #include <vector>
// #include <string>
#include <map>
#include <list>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

/*

inputs

6
0 1
1 2
2 3
3 4
4 5
0 3

6
1 2
2 3
3 4
4 5
5 1
4 2
*/


template<typename t>
class graph
{
public:
	map<t, list<t>> m;

	void add_edge(t a, t b, bool undirected = true)
	{
		m[a].push_back(b);
		if(undirected)	m[b].push_back(a);
	}

	void BFS(t src)	//Undirected
	{
		unordered_map<t, bool> visited;
		for(pair<t, list<t>> nodes : m)
		{
			visited[nodes.first] = false;
		}

		queue<t> q;
		q.push(src);
		visited[src] = true;
		while(!q.empty())
		{
			t node = q.front();
			q.pop();
			cout<< node<<" ";
			for(t nbr : m[node])
			{
				if(!visited[nbr])	
				{
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		cout<<endl;
	}

	void dfs_helper(t src, unordered_map<t, bool> &visited)
	{
		visited[src] = true;
		cout<<src<<" ";
		for(t nbr : m[src])
		{
			if(!visited[nbr])	dfs_helper(nbr, visited);
		}
	}

	void DFS(t src)
	{
		unordered_map<t, bool> visited;
		for(pair<t, list<t>> nodes : m)
		{
			visited[nodes.first] = false;
		}

		dfs_helper(src, visited);
		cout<<endl;
	}

	void components_helper(t src, unordered_map<t, bool> &visited)
	{
		visited[src] = true;
		for(t nbr : m[src])
		{
			if(!visited[nbr])	components_helper(nbr, visited);
		}
	}

	void no_of_components()
	{
		unordered_map<t, bool> visited;
		for(pair<t, list<t>> nodes : m)
		{
			visited[nodes.first] = false;
		}

		int cnt = 0;
		for(pair<t, list<t>> nodes : m)
		{
			if(!visited[nodes.first])
			{
				cnt++;
				components_helper(nodes.first, visited);
			}
		}
		cout<<"Components = "<<cnt<<endl;
	}

	//single source shortest path = undirected
	void SSSP(t src)
	{
		unordered_map<t, int> dist;
		for(pair<t, list<t>> nodes : m)
		{
			dist[nodes.first] = INT_MAX;
		}

		queue<t> q;
		q.push(src);
		dist[src] = 0;
		while(!q.empty())
		{
			t f = q.front();
			q.pop();
			for(t nbr : m[f])
			{
				if(dist[nbr] == INT_MAX)
				{
					q.push(nbr);
					dist[nbr] = dist[f] + 1;
				}
			}
		}

		for(pair<t, int> d : dist)
		{
			cout<<src<<" to "<<d.first<<" = "<<d.second<<endl;
		}

	}

	bool cycle_helper_DFS(t src, unordered_map<t, bool> &visited, t par)
	{
		visited[src] = true;
		for(t nbr : m[src])
		{
			if(!visited[nbr])
			{
				bool cycle = cycle_helper_DFS(nbr, visited, src);
				if(cycle)	return true;
			}
			else if(nbr != par)	return true;
		}
		return false;
	}


	void cycle_detection_DFS()
	{
		unordered_map<t, bool> visited;
		for(pair<t, list<t>> nodes : m)
		{
			visited[nodes.first] = false;
		}

		bool cycle = false;
		for(pair<t, list<t>> nodes : m)
		{
			if(!visited[nodes.first])
			{
				cycle = cycle_helper_DFS(nodes.first, visited, nodes.first);
				if(cycle)	break;
			}
		}

		if(cycle)	cout<<"Cycle found"<<endl;
		else		cout<<"No cycle found"<<endl;
	}

	void cycle_detection_BFS()
	{
		unordered_map<t, bool> visited;
		unordered_map<t, t> par;
		for(pair<t, list<t>> nodes : m)
		{
			visited[nodes.first] = false;
			par[nodes.first] = nodes.first;
		}
		queue<t> q;
		bool cycle = false;
		for(pair<t, list<t>> nodes : m)
		{
			if(!visited[nodes.first])
				q.push(nodes.first);
			// visited[nodes.first] = true;
			while(!q.empty())
			{
				t f = q.front();
				q.pop();
				visited[f] = true;
				for(t nbr : m[f])
				{
					if(!visited[nbr])
					{
						q.push(nbr);
						visited[nbr] = true;
						par[nbr] = f;
					}
					else if(par[f] != nbr)
					{
						cycle = true;
						break;
					}
				}
			}
			if(cycle) break;
		}
		if(cycle)	cout<<"Cycle found"<<endl;
		else		cout<<"No cycle found"<<endl;
	}

	void shortest_cycle_DFS_helper(int &ans, unordered_map<t, int> &dist, t src)
	{
		// cout<<src<<endl;
		for(t nbr : m[src])
		{
			if(dist[nbr] == INT_MAX)
			{
				dist[nbr] = dist[src] + 1;
				shortest_cycle_DFS_helper(ans, dist, nbr);
			}
			else if(dist[nbr] != dist[src] - 1 and dist[nbr] < dist[src])
			{
				ans = min(ans, dist[src] - dist[nbr] + 1);
				// cout<<src<<" "<<nbr<<" "<<dist[src] - dist[nbr] + 1<<endl;
			}
		}
		dist[src] = INT_MAX;
	}

	void shortest_cycle_DFS()
	{
		unordered_map<t, int> dist;
		for(pair<t, list<t>> nodes : m)
		{
			dist[nodes.first] = INT_MAX;
		}

		int ans = INT_MAX;
		for(pair<t, list<t>> nodes : m)
		{
			if(dist[nodes.first] == INT_MAX)
			{
				dist[nodes.first] = 1;
				shortest_cycle_DFS_helper(ans, dist, nodes.first);
			}
		}

		if(ans == INT_MIN)	cout<<"No cycle found"<<endl;
		else				cout<<"Shortest_cycle = "<<ans<<endl;

	}

};

int main()
{
	graph<int> g;
	int n;
	cin >> n;
	while(n--)
	{
		int a, b;
		cin >> a >> b;
		g.add_edge(a, b);
	}
	// g.BFS(0);
	// g.DFS(0);
	// g.no_of_components();
	// g.SSSP(0);
	// g.cycle_detection_BFS();
	g.shortest_cycle_DFS();

	return 0;
}