#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

bool search(vector<int>& a, int t) 
{
	int s = 0, e = a.size()-1;
	while(s <= e)
	{
		int m = (s+e)/2;
		if(a[m] == t)	return true;
		if(a[m] >= a[e])
		{
			
		}
		else
		{
			
		}
	}

        
        
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int t;	cin >> t;
	if(search(v, t))	cout<<"Yes";
	else 				cout<<"No";



	return 0;
}