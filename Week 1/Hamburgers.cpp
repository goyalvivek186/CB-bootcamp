#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;
/*
a[0] =	B 
a[1] = 	S
a[2] =	C
*/

bool check(vector<ll> b, vector<int> n, vector<int> &p, ll m, ll r)
{
	for(int i = 0; i < 3; i++)	b[i] *= m;

	for(int i = 0; i < 3; i++)
	{
		if(b[i] == 0)	continue;
		if(n[i] >= b[i])
		{
			n[i] -= b[i];
		}
		else
		{
			b[i] = b[i] - n[i];
			ll cur = p[i] * b[i];
			if(r >= cur)
			{
				r -= cur;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}



ll get(string &st, vector<int> &n, vector<int> &pr, ll r)
{
	vector<ll> b(3, 0);
	for(char ch : st)
	{
		if(ch == 'B')		b[0]++;
		else if(ch == 'S')	b[1]++;
		else if(ch == 'C')	b[2]++;
	}

	ll e = 0;
	ll p = 0;
	for(int i = 0; i < 3; i++)
	{
        if(b[i] == 0)   continue;
		e += n[i]/b[i];
		e++;
		p += pr[i] * b[i];
	}

	e += (r/p);
	e++;
	ll s = 0;
	ll ans = 0;
	while(s <= e)
	{
		ll m = (s+e)/2;
		if(check(b, n, pr, m, r))
		{
			ans = m;
			s = m+1;
		}
		else
		{
			e = m-1;
		}
	}
	return ans;


}



int main()
{
	
		string s;
		cin >> s;
		vector<int> p(3, 0);
		vector<int> n(3, 0);
		for(int i = 0; i < 3; i++)	cin >> n[i];
		for(int i = 0; i < 3; i++)	cin >> p[i];
		ll r;	cin >> r;
		cout<<get(s, n, p, r)<<endl;
	



	return 0;
}