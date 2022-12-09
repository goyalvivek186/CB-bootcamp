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

bool check(string s, string p, int *a)
{
	if(s.size() < p.size())	return false;

	int i = 0, j = 0;
	while(j < s.size())
	{
		if(i == p.size())	return true;
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
	if(i == p.size())	return true;
	return false;
}


int main()
{
	string p, s;
	cin >> p >> s;
	int *a = new int[p.size()]{0};
	get_table(a, p);	//Reset Table
	cout<<p<<endl;
	print_array(a, p.size());

	if(check(s, p, a))	cout<<"YES";
	else				cout<<"NO";

	return 0;
}