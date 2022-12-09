#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int m, n;	cin >> m >> n;
	vector<int> a(m, 0);
	vector<int> b(n, 0);
	for(int i = 0; i < m; i++)	cin >> a[i];
	for(int i = 0; i < n; i++)	cin >> b[i];

	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++)
	{
		cout<<(upper_bound(a.begin(), a.end(), b[i]) - a.begin())<<" ";
	}



	return 0;
}