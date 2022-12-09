#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;

/*
ax + by = gcd(a, b);
a > b;
gcd(a, 0) = a;
x = y1;
y = x1-int(a/b)*y1
*/

int x, y, gcd;

void EED(int a, int b)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		gcd = a;
		return;
	}

	EED(b, a%b);
	int curx = y;
	int cury = x-((a/b)*curx);
	x = curx;
	y = cury;

}

int32_t main()
{
	int a, b;
	cin >> a >> b;
	if(a < b)	swap(a, b);
	EED(a, b);
	cout<<x<<" "<<y;

	return 0;
}