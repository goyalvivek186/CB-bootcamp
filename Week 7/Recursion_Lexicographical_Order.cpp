#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<string> v;
	for(int i = 0; i <= n; i++)
	{
		string s = to_string(i);
		v.push_back(s);
	} 
	sort(v.begin(), v.end());
	for(string s : v)	cout<<s<<" ";

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