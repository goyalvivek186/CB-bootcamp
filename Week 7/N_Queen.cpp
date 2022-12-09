#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

int cnt = 0;
bool canplace(int a[][100], int x, int y, int n)
{
	for(int i = 0; i < x; i++)
	{
		if(a[i][y] == 1)	return false;
	}

	int i = x, j = y;
	while(i >= 0 and j >= 0)
	{
		if(a[i][j] == 1)	return false;
		i--;
		j--;
	}

	i = x;
	j = y;
	while(i >= 0 and j < n)
	{
		if(a[i][j] == 1)	return false;
		i--;
		j++;
	}
	return true;
}

void print(int a[][100], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] == 1)
			{
				cout<<"Q ";
			}
			else
			{
				cout<<". ";
			}
		}
		cout<<endl;
	}
	// cnt++;
}


bool get(int n, int a[][100], int i)
{
	if(i == n)
	{
		cnt++;
		print(a, n);
		return false;
	}
	for(int j = 0; j < n; j++)
	{
		if(canplace(a, i, j, n))
		{
			a[i][j] = 1;
			bool success = get(n, a, i+1);
			if(success)	return true;
			a[i][j] = 0;
		}
	}
	return false;

}


void solve()
{
	int n;
	cin >> n;
	int a[100][100] = {0};
	get(n, a, 0);
	if(cnt == 0)	cout<<"-1";
	// else			cout<<cnt;

}

int main()
{
	int t = 1;	
	// cin >> t;
	while(t--)
	{
		solve();

		// cout<<endl;
	}

	return 0;
}