#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	string s;
	cin >> s;
	int n = s.length(), i = 0, j = s.length()-1;
	bool remove[n] = {0};
	int cnt = 0;
	while(i < j)
	{
		while(i < j and s[i] != '(')	i++;
		while(j > i and s[j] != ')')	j--;
		if(i < j)
		{
			cnt += 2;
			remove[i] = remove[j] = true;
		}
		i++;
		j--;
	}
	if(cnt == 0)
	{
		cout<<"0";
		return;
	}
	cout<<"1"<<endl<<cnt<<endl;
	for(int i = 0; i < n; i++)	if(remove[i])	cout<<i+1<<" ";

}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}