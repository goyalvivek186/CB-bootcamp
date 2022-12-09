#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.first == p2.first)
	{
		p1.second > p2.second;
	}
	return p1.first < p2.first;
}

vector<int> frequencySort(vector<int>& a) 
{
    sort(a.begin(), a.end());
    vector<pair<int, int>> v;
    for(int i = 0; i < a.size(); i++)
    {
    	int e = a[i];
    	int cnt = 1;
    	// i++;
    	while(a[i] == a[i+1] and i < a.size())
    	{
    		i++;
    		cnt++;
    	}
    	v.push_back({cnt, e});
    	// cout<<e<<" "<<cnt<<endl;
    }
    // cout<<endl;
    a.clear();
    sort(v.begin(), v.end(), compare);
    for(pair<int, int> p : v)
    {
    	int cnt = p.first, e = p.second;
    	while(cnt--)
    	{
    		a.push_back(e);
    	}
    }
    return a;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++)	cin >> v[i];
	vector<int> ans = frequencySort(v);
	for(int i : ans)	cout<<i<<" ";

	return 0;
}