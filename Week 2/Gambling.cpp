#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long



using namespace std;

bool compare(int a, int b)
{
	return a > b;
}
void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}

int main()
{
	int n;	cin >> n;
	vector<int> a(n, 0), b(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	for(int i = 0; i < n; i++)	cin >> b[i];
	sort(a.begin(), a.end(), compare);
	sort(b.begin(), b.end(), compare);
	// print_vector(a);
	// print_vector(b);
	ll s1 = 0, s2 = 0;
	int i = 0, j = 0;
	bool turn_a = true;
	while(i < n and j < n)
	{
		if(b[j] > a[i])
		{
			j++;
		}
		else
		{
			// cout<<"s1 += "<<a[i]<<endl;
			s1 += a[i];
			i++;
		}
		turn_a = false;
		if(i >= n or j >= n)	break;
		if(a[i] > b[j])
		{
			i++;
		}
		else
		{
			// cout<<"s2 += "<<b[j]<<endl;
			s2 += b[j];
			j++;
		}
		turn_a = true;
	}

	if(!turn_a and i < n)
	{
		i++;
	}
	while(i < n)
	{
		// cout<<"s1 += "<<a[i]<<endl;
		s1 += a[i];
		i+=2;
	}

	if(turn_a and j < n)
	{
		j++;
	}
	while(j < n)
	{
		// cout<<"s2 += "<<b[j]<<endl;
		s2 += b[j];
		j+=2;
	}

	cout<<s1-s2<<endl;



	return 0;
}