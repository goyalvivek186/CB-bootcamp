#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a = new int[n]{0};
	int mi = INT_MAX, ma = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
	}
	int m = max(abs(mi), ma);
	int n2 = (2*m) + 1;
	int *fre = new int[n2]{0};

	for(int i = 0; i < n; i++)
	{
		fre[a[i] + m]++;
	}
	int cnt = 0;
	for(int i = 0; i < n2; i++)
	{
		if(fre[i] > 0)
		{
			cnt += fre[i];
			cout<<i-m<<"\t"<<fre[i]<<endl;
		}
	}
	cout<<cnt;



	return 0;
}