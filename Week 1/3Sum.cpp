#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int t;	cin >> t;
	while(t--)
	{
		bool ans = false;
		int n;	cin >> n;
		vector<int> a(10, 0);
		int v;
		for(int i = 0; i < n; i++)
		{
			cin >> v;
			a[v%10]++;
		}
		
		vector<int> no;
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < min(a[i], 3); j++)
			{
				no.push_back(i);
			}
		}
		n = no.size();
		for(int i = 0; i < n; i++)
		{
			if(ans)	break;
			for(int j = i+1; j < n; j++)
			{
				if(ans)	break;
				for(int k = j+1; k < n; k++)
				{
					if((no[i] + no[j] + no[k]) % 10 == 3)
					{
						ans = true;
						break;
					}
				}
			}
		}

		if(ans)	cout<<"YES"<<endl;
		else 	cout<<"NO"<<endl;
		a.clear();
	}
	



	return 0;
}