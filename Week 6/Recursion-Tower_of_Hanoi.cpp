#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

int cnt = 0;

/*
a = source
b = destination
c = helper
*/

void tower_of_hanoi(int n, string a, string b, string c)
{
	if(n <= 0)	return;
	tower_of_hanoi(n-1, a, c, b);
	cout<<"Move "<<n<<"th disc from "<<a<<" to "<<b<<endl;
	cnt++;
	tower_of_hanoi(n-1, c, b, a);

}

void solve()
{
	int n;
	cin >> n;
	string a = "T1";
	string b = "T2";
	string c = "T3";
	tower_of_hanoi(n, a, b, c);
	cout<<cnt;

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