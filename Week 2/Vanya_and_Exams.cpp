#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define int long long

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

void print_vector(vector<pair<int, int>> &a)
{
	for(auto i : a)	cout<<i.first<<" "<<i.second<<endl;
	cout<<endl;
}


void solve()
{
	int n, r, avg;	cin >> n >> r >> avg;
	vector<pair<int, int>> v;	//first = marks, second = no of essays for 1 grade
	int curavg = 0;
	int a, b;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		curavg += a;
	}
	if(curavg/n >= avg)
	{
		cout<<"0";
		return;
	}
	int cnt = (avg*n - curavg);

	sort(v.begin(), v.end(), compare);
	int ans = 0;
	
	for(int i = 0; i < n; i++)
	{
		while(v[i].first >= r)	i++;
		if(i >= v.size())
		{
			cout<<"0";
			return;
		}
		int rem = r - v[i].first;
		if(rem <= cnt)
		{
			ans += v[i].second * rem;
			cnt -= rem;
			
		}
		else
		{
			ans += v[i].second * (cnt);
			cnt = 0;
		}
		if(cnt == 0)	break;
	}
	cout<<ans;

}

int32_t main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}