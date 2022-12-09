#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

class dataa
{
public:
	int t, l, u;
	void set(int a, int b, int c)
	{
		t = a;
		l = b;
		u = c;
	}
};

bool check(int cti, int ctm, int n, dataa *time)
{
	for(int i = 0; i < n; i++)
	{
		if(i == n-1)
		{

		}
		else
		{
			if(time[i].t - cti <= abs(ctm - time[i].l))
			{
				
				if(time[i+1].u > time[i].l)
				{

				}
				else
				{

				}
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}


int main()
{
	int t;	cin >> t;
	while(t--)
	{
		int n, ctm;	cin >> n >> ctm;
		// dataa *time = new dataa[n];
		dataa time[n];
		for(int i = 0; i < n; i++)
		{
			int a, b, c;	cin >> a >> b >> c;
			time[i].set(a, b, c);
		}
		int cti = 0;
		if(check(cti, ctm, n, time))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}



	return 0;
}