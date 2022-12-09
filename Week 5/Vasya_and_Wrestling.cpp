#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define int long long

using namespace std;


string check(vector<int> &a, vector<int> &b)
{
	string s1 = "first";
	string s2 = "second";
	if(a > b)	return s1;
	else if(b > a)	return s2;
	return "get";

}



void solve()
{
	int n;	cin >> n;
	vector<int> fir;
	vector<int> sec;
	int fir_sum = 0;
	int sec_sum = 0;
	int a;	//check for last
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if(a > 0)
		{
			fir.push_back(a);
			fir_sum += a;
		}
		else
		{
			sec_sum += abs(a);
			sec.push_back(abs(a));
		}
	}
	if(fir_sum > sec_sum)
	{
		cout<<"first";
		return;
	}
	else if(fir_sum < sec_sum)
	{
		cout<<"second";
		return;
	}
	string ans = check(fir, sec);
	if(ans == "get")
	{
		if(a < 0)	cout<<"second";
		else		cout<<"first";
		return;
	}
	cout<<ans;

}

int32_t main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}