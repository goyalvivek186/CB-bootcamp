#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>

#define int long long

using namespace std;

bool compare(pair<char, int> a, pair<char, int> b)
{
	return a.second > b.second;
}

void print_vector(vector<char> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<char> a(n);
	unordered_map<char, int> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	if(k == 0)
	{
		cout<<n;
		return;
	}
	vector<pair<char, int>> s;
	for(pair<char, int> v : m)
	{
		s.push_back(v);
	} 
	sort(s.begin(), s.end(), compare);
	a.clear();
	set<pair<int,char>, greater<pair<char, int>>> st;
	for(auto it : s)
	{
		st.insert(make_pair(it.second, it.first));
		while(it.second--)	a.push_back(it.first);
	}
	// print_vector(a);
	int ans = 0, cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(m[a[i]] == 0)	continue;
		ans++;
		m[a[i]]--;
		if(m[a[i]] == 0)	continue;
		cnt = 0;
		for(auto it = st.begin(); it != st.end(); it++)
		{
			char ch = (*it).second;
			if(m[ch] == 0 or ch == a[i])	continue;
			m[ch]--;
			ans++;
			cnt++;
			if(cnt == k)	break;
		}
		if(cnt < k)	ans += k-cnt;
	}
	cout<<ans;

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