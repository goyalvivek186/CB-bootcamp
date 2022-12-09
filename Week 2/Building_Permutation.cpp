#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	sort(a.begin(), a.end());
	if(a[0] == 1 and a[n-1] == n-1)
	{
		cout<<"0"<<endl;
		return 0;
	}
	
	int t = 1;
	ll cnt = 0;

	for(int i = 0; i < n; i++)
	{
		if(a[i] < t)
		{
			cnt += t-a[i];
		}
		else if(a[i] > t)
		{
			cnt += a[i]-t;
		}
		t++;
	}
	cout<<cnt;


	return 0;
}