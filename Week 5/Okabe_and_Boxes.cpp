#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_set>

#define ll long long

using namespace std;

void solve()
{
	int n;	cin >> n;
	int c = 1;
	vector<int> a;
	int s = 0;
	n = n*2;
	int ans = 0;
	string ch;
	unordered_set<int> x;
	while(n--)
	{
		cin >> ch;
		if(ch[0] == 'a')
		{
			int z;	cin >> z;
			a.push_back(z);
		}
		else
		{
			if((a.size() > 0 and a.back() == c) or a.size() == 0)
			{
				c++;
				if(a.size())	a.pop_back();
			}
			else
			{
				for(int i : a)	x.insert(i);
				a.clear();
				ans++;
				
				x.erase(c);
				
				c++;
			}
		}
		// cout<<ans<<endl;
	}
	cout<<ans;
}

int main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}