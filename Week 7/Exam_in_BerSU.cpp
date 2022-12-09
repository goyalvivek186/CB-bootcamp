#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++)	cin >> a[i];
	int t = 0;
	int fre[101] = {0};
	for(int i = 0; i < n; i++)
	{
		int cur = m - t - a[i];
        // cout<<cur<<"\t";
		if(cur < 0)//prob
		{
			int j = 100;
			int ans = 0;
            int x = cur;
			for(	; j >= 0; j--)
			{
				int cnt = fre[j];
                if(cnt == 0)    continue;
				if((cnt * j) + x == 0)
				{
					//we only nedd all of these
					ans += cnt;
					x = 0;
                    // cout<<"==";

				}
				else if((cnt * j) + x > 0)
				{
					//might not need all of them
					int no = (abs(x) + j)/j;
					x += (no*j);
					ans += no;
                    if(x == j)  ans--;
                    // cout<<"no "<<no<<" "<<"x "<<x<<" ";
                    // cout<<" > "<<ans<<" ";
                    
				}
				else
				{
					//take all of these and check of more
					x += (cnt * j);
					ans += cnt;
                    // cout<<"<";
				}
				if(x >= 0)	break;
			}
			cout<<ans<<" ";
		}
		else
		{
			cout<<"0"<<" ";
		}
		t += a[i];
		fre[a[i]]++;
	}
	

}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		// cout<<endl;
	}

	return 0;
}