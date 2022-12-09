//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// } Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.

vector<int> subarraySum(int a[], int n, long long t)
    {
        vector<int> ans;
        int s = 0, e = 1;
        long long sum = a[0];
        for(; e < n; e++)
        {
            if(sum > t)
            {
                while(sum > t and s < e-1)
                {
                    sum -= a[s];
                    s++;
                    // cout<<"- ";
                }
            }
            if(sum == t)
            {
                ans.push_back(s+1);
                ans.push_back(e+1);
                // cout<<"= "<<endl;
                return ans;
            }
            if(sum < t)
            {
                sum += a[e];
                // cout<<"+ ";
            }
            // cout<<sum<<" ";
        }
        // cout<<endl;
        ans.push_back(-1);
        return ans;
        
    }

};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends