#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;

void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}

int get(int n, int w, vector<int> &s, vector<int> &p, vector<vector<int> > &dp, int i)
{
	if(w < 0)	return 1e11;
	if(w == 0)	return 0;
	if(i >= n)	return 0;

	if(dp[i][w] != -1)	return dp[i][w];

	int op1, op2;
	op1 = op2 = INT_MIN;
	//exclude
	op1 = 0 + get(n, w, s, p, dp, i + 1);

	//include
	if(w - s[i] >= 0)
		op2 = p[i] + get(n, w - s[i], s, p, dp, i + 1);

	return dp[i][w] = max(op1, op2);
}

void solve()
{
	int n, w;
	cin >> n >> w;
	vector<int> s(n), p(n);
	for(int i = 0; i < n; i++)	cin >> s[i] >> p[i];
	
	vector<vector<int> > dp(n, vector<int> (w+1, -1));
	cout << get(n, w, s, p, dp, 0)<<endl;
	// print_vector(dp); 
	

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