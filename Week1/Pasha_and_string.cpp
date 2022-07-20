#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;


void print_array(int *a, int n)
{
	for(int i = 0; i < n; i++)	cout<<a[i]<<" ";
	cout<<endl;
}
void get(string &s, int i)
{
	cout<<i<<endl;
	int n = s.size();
	i--;
	int j = n-i-1;
	// cout<<i<<" "<<j<<endl;
	while(i < j)
	{
		swap(s[i], s[j]);
		i++;
		j--;
	}
}

int main()
{
	// int t;	cin >> t;
	// while(t--)
	// {
		string s;
		cin >> s;
		int n;
		cin >> n;
		int size = (s.length()/2) + 1;
		// cout<<size<<endl;
		int a[size] = {0};
		while(n--)
		{
			int x;
			cin >> x;
			x;
			a[x-1]++;
			
		}
		// print_array(a, size);
		ll sum = 0;
		for(int i = 0; i < size-1; i++)
		{
			sum += a[i];
			if(sum % 2 != 0)	
			{
				swap(s[i], s[s.length()-i-1]);
				// cout<<i<<" "<<s.length()-i-1<<endl;
			}
		}
		// get(s, a);
		cout<<s;
	// }	



	return 0;
}