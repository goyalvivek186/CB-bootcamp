#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <set>
#define ll long long

using namespace std;

void solve()
{
	int n, k;	cin >> n >> k;
	vector<int> a(n, 0);
	unordered_map<int, int> m;
	set<int, greater<int>> s;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i < k)
			m[a[i]]++;
	}
	int i = 0;
	
	while(i < k)
	{
		if(m[a[i]] == 1)	s.insert(a[i]);
		// cout<<m[a[i]]<<" ";
		i++;
	}
	// cout<<endl;
	i = 0;
	if(s.empty())
	{
		cout<<"Nothing"<<endl;
	}
	else
	{
		cout<<*s.begin()<<endl;
	}

	int l = 0, r = k;

	for(int i = 0; i < n-k; i++)
	{
		m[a[l]]--;
		if(m[a[l]] == 1)	s.insert(a[l]);
		else				s.erase(a[l]);
		l++;

		m[a[r]]++;
		if(m[a[r]] == 1)	s.insert(a[r]);
		else				s.erase(a[r]);
		r++;
		
		if(s.empty())
		{
			cout<<"Nothing"<<endl;
		}
		else
		{
			cout<<*s.begin()<<endl;
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