class Solution {
public:

    void get(vector<int> &a, int t, int sum, int &ans, int i)
    {
        if(i == a.size() and sum == t)    ans++;
        if(i >= a.size())   return;

        //add
        get(a, t, sum + a[i], ans, i+1);
        //subtract
        get(a, t, sum - a[i], ans, i+1);

    }



    int findTargetSumWays(vector<int>& a, int t) 
    {
        int ans = 0;
        get(a, t, 0, ans, 0);
        return ans;
        
    }
};