#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;


bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.first == p2.first)
	{
		return p1.second > p2.second;
	}
	return p1.first > p2.first;
}

bool check(vector<pair<int, int>> &d, vector<int> e, ll mid )
{
    // cout<<"e.size = "<<e.size();
	int s = 1;
    // cout<<endl<<"mid "<<mid<<endl;
	for(int i = 0; i < d.size(); i++)
	{
		int cnt = 0;
		int j = s;
		int prep = d[i].first;
		int exam = d[i].second;
		while(j < e.size() and cnt < prep)
		{
			if(e[j] != -1)	cnt++;
            // cout<<e[j]<<" = -1 "<<endl;
			e[j] = -1;
			j++;
		}
        
		if(cnt != prep)	//return false;
        {
            // cout<<"first"<<endl;
            return false;
        }
		s = j;
		while(j < e.size() and j <= mid)
		{
			if(e[j] == exam)
			{
                // cout<<"Exam "<<j<<" "<<e[j]<<endl;
				e[j] = -1;
				break;
			}	
            j++;
		}
        if(j > mid) //return false;
        {
            // cout<<"Second"<<endl;
            return false;
        }
        // cout<<endl;
	}
	return true;
}


int main()
{
	int m, n;	cin >> n >> m;
	n++;
	vector<int> exam(n, 0);
	vector<pair<int, int>> days;
	for(int i = 1; i < n; i++)	cin >>exam[i];
	ll s = 0;
	for(int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		days.push_back({x, i});		//first = days to prep, second = exam no
		s += x;
	}
	sort(days.begin(), days.end(), compare);
	//s = 0;
	ll e = n-1;
	ll ans = -1;
	while(s <= e)
	{
		ll mid = (s+e)/2;
		if(check(days, exam, mid))
		{
			ans = mid;
			e = mid-1;
		}
		else	s = mid+1;
	}

	cout<<ans;



	return 0;
}