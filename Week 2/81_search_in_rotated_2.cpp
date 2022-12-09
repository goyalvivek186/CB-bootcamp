#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

bool search(vector<int>& a, int t)
{
	int s = 0, e = a.size()-1;
	while(s < e)
	{
		int m = (s+e)/2;
		if(a[m] == t)	return true;
		
		if(a[m] == t)	e--;
		else if(a[m] > e)
		{
			if(a[m] > t)
			{

			}
			else
			{

			}
		}	
	}
}



int main()
{
	int n;
	vector<int> a(n,0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	int t;
	cin >> t;
	if(search(a, t))	cout<<"YES";
	else				cout<<"NO";


	return 0;
}