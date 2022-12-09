#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

void check(int i, vector<int> &a, int t, vector<vector<int> > &ans, unordered_map<int, int> m, set<vector<int> >&s)
{
	int n = a.size();
	int j = i+1, k = n-1;
	m[a[j]]--;
	m[a[k]]--;
	vector<int> p;
	
	while(j < k)
	{
		p.clear();
		
		ll cur = a[i] + a[j] + a[k];
		if(m.count(t-cur) > 0 and m[t-cur] > 0)
		{
			p.push_back(a[i]);
			p.push_back(a[j]);
			// int cnt = 1;
			for(int x = j+1; x < k; x++)
			{
				if(a[x] == (t-cur))
				{
					p.push_back(a[x]);
					p.push_back(a[k]);
					break;
				}
			}
		}
		if(cur < t)		
		{
			j++;
			m[a[j]]--;
		}
		else
		{
			k--;
			m[a[k]]--;
		}
		if(p.size())	s.insert(p);
	}

	
}

vector<vector<int>> fourSum(vector<int>& a, int t)
{
	set<vector<int> >s;
	sort(a.begin(), a.end());
	unordered_map<int, int> m;
	for(int i = 0; i < a.size(); i++)
	{
		if(m.count(a[i] == 0))	m[a[i]] = 1;
		else					m[a[i]]++;
	}
	vector<vector<int> > ans; 
	for(int i = 0; i < a.size(); i++)
	{
		m[a[i]]--;
		check(i, a, t, ans, m, s);
	}
	for(auto it = s.begin(); it != s.end(); it++)
	{
		ans.push_back(*it);
	}
	return ans;
}


int main()
{
	int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++)  cin >> v[i];
    int t;
    cin >> t;
    vector<vector<int> > ans = fourSum(v, t); 	
    for(auto x : ans)
    {
    	for(int i : x)	cout<<i<<" ";
    	cout<<endl;
    }


	return 0;
}