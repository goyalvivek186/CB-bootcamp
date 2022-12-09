#include <iostream>
#include <vector>
#include <cstring>
// #include "bits/stdc++.h"
#define ll long long

using namespace std;

// -1 = exception
// 1 = prime
// 0 = non prime = composite


void print_vector(vector<ll> &a)
{
	for(auto i : a)	cout<<i<<endl;
	// cout<<endl;
}

vector<int> create_seive(int n)
{
	int a[n]{0};
	a[0] = a[1] = -1;
	a[2] = 1;
	for(int i = 3; i < n; i += 2)	a[i] = 1;

	for(int i = 3; i*i < n; i++)
	{
		if(a[i])
		{
			for(int j = i*i; j < n; j += i)	a[j] = 0;
		}
	}

	vector<int> primes;
	for(int i = 2; i < n; i++)	if(a[i])	primes.push_back(i);
	return primes;
}

vector<ll> create_segment(ll a, ll b, vector<int> &seive)
{
	int primes[b-a+1];
	memset(primes, 1, sizeof(int) * (b-a+1));
	for(int i = 0; seive[i]*seive[i] <= b; i++)
	{
		// int e = seive[i];
		ll start = (a/seive[i]) * seive[i];
		if(start < a)	start += seive[i];
		for(ll j = start; j <= b; j+=seive[i])
		{
			primes[j-a] = 0;
		}
		if(start == primes[i])	primes[start-a] = 1;
	}

	vector<ll> ans;
	for(ll i = a; i <= b; i++)
	{
		if(primes[i - a])	ans.push_back(i);
	}
	return ans;

} 


int main()
{
	int n = 100000005;
	// int n = 150;
	vector<int> primes = create_seive(n);
	// print_vector(primes);
	int t;
	cin >> t;
	while(t--)
	{
		ll a, b;
		cin >> a >> b;
		if(b <= n)
		{
			// cout<<"seive"<<endl;
			for(int i : primes)
			{
				if(i >= a and i <= b)	cout<<i<<endl;
			}
		}
		else
		{
			// cout<<"Segment"<<endl;
			vector<ll> segemt = create_segment(a, b, primes);
			print_vector(segemt);
		}
	cout<<endl;	
	}
	

	return 0;
}