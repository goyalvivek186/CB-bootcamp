#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#define ll long long

using namespace std;

void get(string s, string cur, vector<string> &ans, int i = 0)
{
	if(i == s.length())
	{
		if(cur.length() > 0)	ans.push_back(cur);
        // cout<<cur<<endl;
		return;
	}

	//op1;
	char x = s[i]-'1' + 'a';
	// cout<<x;
	cur.push_back(x);
	get(s, cur, ans, i+1);
	cur.pop_back();


	//op2;
	if(i+1 < s.length())
	{
		int n = s[i] - '0';
		n = n*10;
		n += s[i+1] - '0';
		x = n + 'a'-1;
		// cout<<n;
		// cout<<x;
		if(n <= 26)
		{
			cur.push_back(x);
			get(s, cur, ans, i+2);
			cur.pop_back();
		}
	}

}


void solve()
{
	string a;
	cin >> a;
	string cur;
	vector<string> ans; 
	get(a, cur, ans);
    int n = ans.size();
    if(n == 0)  return;
    cout<<"[";
    for(int i = 0; i < n; i++)
    {
        cout<<ans[i];
        if(i == n-1)    cout<<"]";
        else            cout<<", ";   
    }
	

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