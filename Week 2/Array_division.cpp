#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main()
{
	int n;
	cin >> n;
	ll m = 0;
	int a;
	// for(int i = 0; i < n; i++)
	// {
	// 	cin >> a;
	// 	a = a % 2;
	// 	m += a;
	// 	m = m % 2;
	// 	// cout<<a<<" "<<m<<endl;
	// }
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		m += a;

	}
	cout<<m;
	// if(m == 0)	cout<<"YES";
	// else cout<<"NO";
	



	return 0;
}