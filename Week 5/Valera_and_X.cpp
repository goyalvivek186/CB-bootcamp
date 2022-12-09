#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

bool check(char s[][301], int n, int mask[][301])
{
	char d;
	d = s[0][0];
	int i = 0, j = 0;
	while(i < n and j < n)
	{
		if(s[i][j] != d)	return false;
		mask[i][j] = 1;
		i++;
		j++;
	}
	i = 0, j = n-1;
	while(i < n and j >= 0)
	{
		if(s[i][j] != d)	return false;
		mask[i][j] = 1;
		i++;
		j--;
	}
	return true;
}

void solve()
{
	int n;
	cin >> n;
	char s[301][301];
	int mask[301][301] = {0};
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)	cin >> s[i][j];
	}
	
	bool X = check(s, n, mask);
	if(!X)
	{
		cout<<"NO";
		return;
	}
	char t = s[0][1];
	char d = s[0][0];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(mask[i][j] == 1)	continue;
			if(s[i][j] != t or s[i][j] == d)
			{
				cout<<"NO";
				return;
			}
		}
	}
	cout<<"YES";
	return;
}

int main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}