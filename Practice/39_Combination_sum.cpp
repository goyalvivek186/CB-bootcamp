
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

void print_vector(vector<int> &a)
{
    for(auto i : a)    cout<<i<<" ";
    cout<<endl;
}


void get(vector<int> &a, int t, set<vector<int> > &s, vector<int> cur, int sum = 0, int i = 0)
{
    if(i >= a.size())
    {
        return;
    }
    if(cur.size() > 150)    return;
    if(sum == t)
    {
        s.insert(cur);
        return;
    }
    if(sum > t) return;
    get(a, t, s, cur, sum, i+1);
    sum += a[i];
    cur.push_back(a[i]);
    get(a, t, s, cur, sum, i);
    get(a, t, s, cur, sum, i+1);
}

vector<vector<int>> combinationSum(vector<int>& a, int target) 
{
    set<vector<int>> s;
    vector<vector<int>> ans;
    vector<int> cur;
    get(a, target, s, cur); 
    for(auto it = s.begin(); it != s.end(); it++)
    {
        ans.push_back(*it);
    }
    return ans;
}


void solve()
{
    int n;  cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++)  cin >> v[i];
    int t;  cin >> t;
    vector<vector<int> > ans = combinationSum(v, t);
    for(auto it : ans)
    {
        for(int x : it)
        {
            cout<<x <<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int t = 1;    
    //cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}