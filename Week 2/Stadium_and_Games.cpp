#include <iostream>
#include <vector>
#include <string>

#define int long long

using namespace std;

bool check(int n, int m, vector<int> &ans)
{
	int x = m;
	int cur = 0;
	while(m % 2 == 0)
	{
		cur += m/2;
		if(m % 2 == 0)	m = m/2;
		// else			m = m/2 + 1;
	}
	if(m == 1)	
	{
		ans.push_back(x);
		return true;
	}
	cur += (m*(m-1))/2;
	// cur /= 2;
	cout<<" "<<cur<<endl;
	if(cur == n)	ans.push_back(x);
	if(cur <= n)	return true;
	return false;
}

int32_t main()
{
	int n;	cin >> n;
	int s = 0, e = 2*n;
	// int ans = -1;
	vector<int> ans;
	// check(25, 20, ans);
	
	// while(s <= e)
	for(int i = s; i <= e; i++)
	{
		int m = i;
		cout<<"m "<<m;
		if(check(n, m, ans))
		{
			// ans = m;
			// cout<<ans<<endl;
			s = m+1;
		}
		else
		{
			e = m-1;
		}
	}
	if(ans.size() == 0)	cout<<-1;
	else
	{
		for(int i : ans)	cout<<i<<endl;
	}


	return 0;
}