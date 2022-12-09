#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;
/*
a > b
gcd(d, 0) = d
ax + bx = gcd(a, b);

ab % m = 1;
ab + m*k' = 1
if(gcd(a, m) == 1)	the the ans can be calculated via EED
*/

int x, y, gcd;
void EED(int a, int b)
{
	if(b == 0)
	{
		x = a;
		y = 0;
		gcd = a;
		return;
	}

	EED(b, a%b);

	int curx = y;
	int cury = x - ((a/b)*y);
	x = curx;
	y = cury;
}

void MMI(int a, int m)
{
	if(__gcd(a, m) != 1)
	{
		cout<<"No answer";
		exit(0);
	}
	EED(a, m);
	x = (x + m) % m;	//-ve ans
}



int32_t main()
{
	int a, m;
	cin >> a >> m;
	if(a < m)	swap(a, m);
	MMI(a, m);
	cout<<x;
	

	return 0;
}