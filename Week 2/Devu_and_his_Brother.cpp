#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
	int m, n;
	cin >> n >> m;
	vector<int> a(n, 0);		//my
	vector<int> b(m, 0);		//Brother
	for(int i = 0; i < n; i++)	cin >> a[i];
	for(int i = 0; i < m; i++)	cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	ll ans = 0;
	for(int i = 0; i < min(m, n); i++)
	{
		if(a[i] >= b[i])	break;
		ans = ans + b[i] - a[i];
	}
	cout<<ans;



	return 0;
}