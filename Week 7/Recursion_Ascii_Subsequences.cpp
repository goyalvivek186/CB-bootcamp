#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

void get(string s, string cur, int i, int &cnt, vector<string> &ans)
{
	if(i == s.length())
	{
		cnt++;
		ans.push_back(cur);
		// cout<<ans<<" ";
		return;
	}
	//op1	skip
	get(s, cur, i+1, cnt, ans);

	//op1	include no
	cur.push_back(s[i]);
	get(s, cur, i+1, cnt, ans);
	cur.pop_back();

	//op3	include ascii
	int x = s[i];
	string y = to_string(x);
	string curr = cur + y;
	get(s, curr, i+1, cnt, ans);

}

bool compare(string a, string b)
{
	return a > b;
}



void solve()
{
	string s;
	cin >> s;
	string cur;
	vector<string> ans; 
	int cnt = 0;
	get(s, cur, 0, cnt, ans);

	// sort(ans.begin(), ans.end(), compare);
	for(string st : ans)	cout<<st<<" ";
	cout<<endl<<cnt;

}

int main()
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