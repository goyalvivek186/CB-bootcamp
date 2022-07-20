#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

vector<int> sortedSquares(vector<int>& a) 
{
	int s = 0, e = a.size()-1;
	vector<int> ans(a.size(), 0);
	int i = a.size()-1;
	while(s <= e)
	{
		int l = a[s]*a[s];
		int r = a[e]*a[e];
		if(l > r)
		{
			ans[i] = l;
			s++;
		}
		else
		{
			ans[i] = r;
			e--;
		}
		i--;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	v = sortedSquares(v);
	for(int i : v)	cout<<i <<" ";


	return 0;
}