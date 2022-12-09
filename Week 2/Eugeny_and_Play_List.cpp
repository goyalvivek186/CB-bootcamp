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
	vector<int> t(n, 0);
	int x, y;
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		t[i] = x*y;
		t[i] += s;
		s = t[i];
	}
	while(m--)
	{
		cin >> x;
		int ind = upper_bound(t.begin(), t.end(), x) - t.begin();
		if(ind != 0 and t[ind-1] == x)	cout<<ind;
		else			cout<<ind + 1;
		cout<<endl;
	}
	



	return 0;
}