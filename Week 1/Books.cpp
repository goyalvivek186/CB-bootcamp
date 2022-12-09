#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, t;	cin >> n >> t;
	vector<int> v(n+1, 0);
	for(int i = 1; i < n+1; i++)
	{
		cin >> v[i];
		v[i] += v[i-1];
	}
	int i = 0, j = 0;
	int cnt = 0;
	while(j < n+1 and i < n+1)
	{
		int cur = 0;
		if(i == j)
		{
			if(v[j] - v[i] <= t)
			{
				cur = j-i;
			}
			j++;
		}
		else
		{
			if(v[j] - v[i] <= t)
			{
				cur = j-i;
				j++;
			}
			else
			{
				i++;
			}
		}
		
		cnt = max(cnt, cur);
	}
	cout<<cnt;



	return 0;
}