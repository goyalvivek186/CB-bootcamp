#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

int get(vector<int> &v, int i)
{
	if(i == v.size())	return 0;
	return v[i] + get(v, i+1);
}

int solve()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	return get(a, 0);

}

int main()
{
	int t = 1;	
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cout<<"Case "<<i<<": "<<solve()<<endl;
	}

	return 0;
}