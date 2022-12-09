#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

void get_table(int *a, const string &p)
{
	//1 Based indexing
	int i = 0, j = 1;
	while(j < p.size())
	{
		while(i > 0 and p[i] != p[j])
		{
			i = a[i-1];
		}

		if(p[i] == p[j])
		{
			a[j] = i+1;
			j++;
			i++;
		}
		else
		{
			j++;
		}
	}
}

void print_array(int *a, int n)
{
	for(int i = 0; i < n; i++)	cout<<a[i];
	cout<<endl;
}

int check(string s, string p, int *a, int *b)
{
	int cnt = 0;
	if(s.size() < p.size())	return cnt;

	int i = 0, j = 0;
	while(j < s.size())
	{
		if(i == p.size())
		{
			cnt++;
			i = 0;
			if(b[j] != 0)
				j = b[j]-1;
		}
		if(p[i] == s[j])
		{
			i++;
			j++;
		}
		else if(i == 0)	j++;
		else
		{
			if(a[i] != 0)
				i = a[i]-1;
			else
				i = 0;
		}
	}
	if(i == p.size())	cnt++;
	return cnt;
}

int main()
{
	int n, t;	cin >> n >> t;
	string p, s;
	cin >> s;
	int *b = new int[s.size()]{0};
	get_table(b, s);
	while(t--)
	{
		cin >> p;
		int *a = new int[p.size()]{0};
		get_table(a, p);

		cout<<check(s, p, a, b)<<endl;
	}

	return 0;
}



