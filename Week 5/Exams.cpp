#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define int long long

using namespace std;

bool check(int n, int m, vector<int> &e, vector<int> &d, int mid)
{
	vector<int> date(mid, -1);
	vector<bool> done(m, 0);
	int cnt = 0;
    // cout<<"M = "<<mid<<endl;

	for(int i = mid-1; i >= 0; i--)
	{
		if(e[i] == 0 or done[e[i] - 1])
		{
			continue;
		}
		else
		{
			date[i]	 = e[i];
			done[e[i]-1] = true;
			cnt++;
		}
	}
    // for(int i : date)   cout<<i<<" ";
    // cout<<endl;
    
	if(cnt < m)	
    {
        // cout<<cnt<<" < "<<n<<endl;
        return false;
    }
	int h = 0;
	for(int i = 0; i < mid; i++)
	{
        // cout<<i<<" "<<h<<" "<<date[i]<<" "<<
		if(date[i] == -1)	h++;
		else
		{
			if(d[date[i]-1] > h)	
            {
                // cout<<h<<" "<<d[date[i]-1]<<" "<<i<<endl;
                return false;
            }
			else
			{
				h = h - d[date[i]-1];
			}
		}
	}
	return true;
    
}


void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> exams(n, 0);
	vector<int> days(m, 0);
	for(int i = 0; i < n; i++)	cin >> exams[i];
	int s = 0;
	int e = m;
	for(int i = 0; i < m; i++)
	{
		cin >> days[i];
		e += days[i];
	}
	e++;
    // check(n, m, exams, days, (s+e)/2);
	int ans = -1;
	while(s < e)
	{
		int mid = (s+e)/2;
		if(check(n, m, exams, days, mid))
		{
			ans = mid;
			e = mid-1;
		}
		else
		{
			s = mid+1;
		}
        // cout<<endl;
	}
	cout<<ans;

}

int32_t main()
{
	int t = 1;	
	//cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}