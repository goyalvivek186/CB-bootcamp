#include <iostream>
#include <vector>
#include <string>
using namespace std;

int partitionDisjoint(vector<int>& a) 
{
	int n = a.size();
	if(n == 2)	return 1;
	int i = 0, j = 1;
	int ma = a[0];	//right
	int mi = a[0];	//Left max
	while(j < n)
	{
		if(a[j] < mi)
		{
			i = j;
			mi = ma;
		}
		ma = max(ma, a[j]);
		j++;
	}
    return  i+1;    
}

int main()
{
	int n;	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];	
	cout<<partitionDisjoint(a);


	return 0;
}