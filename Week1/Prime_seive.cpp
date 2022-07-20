#include <iostream>
#include <vector>
#include <string>
#include <cstring>
// #include <bits/stdc++.h>
#define ll long long

using namespace std;

void seive(int *a, int n)
{
	a[0]  = a[1] = -1;
	for(int i = 4; i < n; i+=2)	a[i] = 0;

	for(int i = 3; i*i < n; i+=2)
	{
		if(a[i])
		{
			for(int j = i*i; j < n; j+=i)
			{
				a[j] = 0;
			}
		}
	}
}



int main()
{

	int n;	cin>> n;
	int *a = new int[n];
	// bitset<n> prime;
	memset(a, 1, sizeof(int)*n);
	seive(a, n);
	for(int i = 2; i < n; i++)	if(a[i])	cout<<i<<" ";

	delete []a;
	return 0;
}