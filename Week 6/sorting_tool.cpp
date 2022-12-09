#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#define ll long long

using namespace std;

unordered_map<int, int> mp;
int dif;
bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.first == p2.first)
	{
		return mp[p1.second - dif] < mp[p2.second - dif];
	}
	return p1.first > p2.first;
}

void solve()
{
	int x, n;
	cin >> x >> n;
	vector<int> arr(x, 0);
	int mi = INT_MAX;
	int ma = INT_MIN;
	// unordered_map<int, int> m;
	for(int i = 0; i < x; i++)
	{
		cin >> arr[i];
		if(mp.count(arr[i]) == 0)	mp[arr[i]] = i;
		mi = min(mi, arr[i]);
		ma = max(ma, arr[i]);
	}
	int m = max(abs(mi), ma);
	m++;
	vector<int> a(2*m, 0);
	for(int i = 0; i < x; i++)
	{
		a[arr[i] + m]++;
	}
	dif = m;
    // cout<<m<<endl;
	vector<pair<int, int>> v;
	for(int i = 0; i < 2*m; i++)
	{
        // cout<<i<<"\t"<<a[i]<<endl;
		if(a[i] > 0)
		{
			v.push_back(make_pair(a[i], i));
		}
	} 
	sort(v.begin(), v.end(), compare);
	for(pair<int, int> p : v)
	{
		// while(p.first--)	cout<<p.second - m<<" ";
        for(int i = 0; i < p.first; i++)    cout<<p.second-m<<" ";
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