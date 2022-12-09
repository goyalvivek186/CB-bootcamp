#include <iostream>
#include <vector>
#include <string>
#include <climits>
#define ll long long

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n+1, 0);	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i-1];
	}

	int i = 0, j = k;
	int p = -1, m = INT_MAX;
	while(j <= n)
	{
		int cur = a[j] - a[i];
		if(cur < m)
		{
			m = cur;
			p = i+1;
			cout<<i<<" "<<j<<endl;
		}
		j++;
		i++;
	}
	cout<<p;


	return 0;
}