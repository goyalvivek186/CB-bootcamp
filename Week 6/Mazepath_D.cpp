#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

//V = vertical
//H = horizontal
//D = diagnal

int cnt = 0;

void print_vector(vector<char> &a)
{
	for(auto i : a)	cout<<i;
	cout<<" ";
}

void get(int m, int n, vector<char> &ans, int i, int j)
{
	if(i == m-1 and j == n-1)
	{
		print_vector(ans);
		cnt++;
		return;
	}
	if(i >= m)	return;
	if(j >= n)	return;

	ans.push_back('V');
	get(m, n, ans, i+1, j);
	ans.pop_back();
	
	ans.push_back('H');
	get(m, n, ans, i, j+1);
	ans.pop_back();

	ans.push_back('D');
	get(m, n, ans, i+1, j+1);
	ans.pop_back();
}


void solve()
{
	int m, n;	cin >> m >> n;	//m = row, n = col
	vector<char> ans;
	get(m, n, ans, 0, 0);
	cout<<endl<<cnt;
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