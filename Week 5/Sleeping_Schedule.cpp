#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

int get(vector<int> &a, int n, int h, int l, int r, int i, int waking = 0)
{
	if(i == n)
	{
		return 0;
	}
	int op1 , op2;
	// int x = get(a, n, h, l, r, i+1)
	op1 = a[i] + waking;
	op2 = a[i] + waking - 1;
	op1 = op1 % h;
	op2 = op2 % h;
	int ans1, ans2;
	ans1 = ans2 = 0;
	if(op1 >= l and op1 <= r)	ans1++;
	if(op2 >= l and op2 <= r)	ans2++;

	return max(get(a, n, h, l, r, i+1, op1) + ans1, get(a, n, h, l, r, i+1, op2) + ans2);
}

void solve()
{
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	int cnt = 0;
	cout<<get(a, n, h, l, r, 0);	

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