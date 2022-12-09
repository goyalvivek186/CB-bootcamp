#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
// #include <climits>

#define int long long

using namespace std;

void print_vector(vector<int> &a)
{
	for(auto i : a)	cout<<i<<" ";
	cout<<endl;
}
void solve()
{
	int n, k;
	cin >> k >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)	cin >> a[i];
	vector<int> s(a.begin(), a.end());
	sort(s.begin(), s.end());
	int j = 0;
	stack<int> st;
	vector<int> ans;
	for(int i = 0; i < n; i++)
	{
		st.push(a[i]);
		while(!st.empty() and st.top() == s[j])
		{
			ans.push_back(st.top());
			st.pop();
			j++;
		}
	}
	// print_vector(ans);
	while(!st.empty() and st.top() == s[j])
		{
			ans.push_back(st.top());
			st.pop();
			j++;
		}
	// print_vector(ans);
	if(!st.empty())
	{
		cout<<"-1";
		return;
	}
	print_vector(a);
	unordered_set<int> p;
	for(int i = 0; i < n; i++)
	{
		
		if(binary_search(s.begin(), s.end()))
		if(p.find(s[i]) == p.end())
		{
			int ind = s.end() - upper_bound(s.begin(), s.end(), s[i]+1);
			if(ind != n)
			{
				cout<<"-1";
				return;
			}
			for(int j = s[i]; j >= 1; j--)
			{
				if(p.find(j) != p.end())	break;
				p.insert(j);
				a.push_back(j);
			}
		}
		
	}
	print_vector(a);


}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	cin >> t;
	while(t--)
	{
		solve();

		//cout<<endl;
	}

	return 0;
}