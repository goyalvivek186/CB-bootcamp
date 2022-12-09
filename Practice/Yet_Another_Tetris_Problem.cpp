#include <iostream>
#include <vector>
#include <string>
#include <climits>
#define ll long long

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n] = {0};
		int mi = INT_MAX;
		int ma = INT_MIN;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			mi = min(mi, a[i]);
			ma = max(ma, a[i]);
		}
		if((ma - mi) % 2 != 0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		
	}
	



	return 0;
}