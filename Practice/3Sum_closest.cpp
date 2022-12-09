#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;

int threeSumClosest(vector<int>& a, int t)
{
    sort(a.begin(), a.end());
    int n = a.size();
    int ans = 50000;
    for(int i = 0; i < n-2; i++)
    {
        int j = i+1;
        int k = n-1;
        while(j < k)
        {
            int cur = a[i] + a[j] + a[k];
            // ans = min(abs(cur - t), ans);
            if(abs(t-cur) < abs(ans - t))
            {
                cout<<a[i]<<" "<<a[j] << " "<<a[k]<< "\t"<<cur<<endl;
                ans = cur;
            }
            if(cur > t) k--;
            else        j++;
        }
        if(ans == t)    break;
    }
    return ans;

}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++)  cin >> v[i];
    int t;
    cin >> t;
    cout<<threeSumClosest(v, t);



    return 0;
}
