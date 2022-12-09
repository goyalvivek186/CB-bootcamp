#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>
// #include <climits>
#include <map>
#define int long long
 
using namespace std;
 
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	map<int, int> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	if(m.size() == 1)	cout<<"NO";
	else
	{
		auto it = m.begin();
		it++;
		cout<<(*it).first;
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