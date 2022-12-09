#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <climits>

#define int long long

using namespace std;

string get(string s)
{
	{
	    int N = s.size(), right = -1;
	    for (int i = 0; i < N; ++i) {
	        if (s[i] == 'L') {
	            if (right == -1) { 
	                for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
	                  s[j] = 'L';  
	                } 
	            } else {
	                for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
	                    s[j] = 'R';
	                    s[k] = 'L';
	                } 
	                right = -1;
	            }
	        } else if (s[i] == 'R') {
	            if (right != -1) {
	                for (int j = right + 1; j < i; ++j) s[j] = 'R';
	            }
	            right = i;
	        }
	    }
	    if (right != -1) {
	        for (int j = right + 1; j < N; ++j) s[j] = 'R';
	    }
	    return s;
	}
}

void solve()
{
	string s;
	cin >> s;
	cout<<get(s);

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

		//cout<<endl;
	}

	return 0;
}