#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

void solve()
{
	int n;	cin >> n;
	cout<<n<<" ";
	float f = n/1.0;
	cout<<(f == n*1.0)<<endl;

}

int main()
{
	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}