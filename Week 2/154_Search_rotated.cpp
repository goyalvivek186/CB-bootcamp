#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}

int findMin(vector<int>& a)
{
	int n = a.size();
	int s = 0, e = n-1;
	while(s < e)
	{
		int m = (s+e)/2;
		if(a[m] == a[e])	e--;
		else if(a[m] > a[e])		s = m+1;
		else						e = m;
	}
	return a[e];

}


int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	// print_vector(a);
	cout<<findMin(a);



	return 0;
}