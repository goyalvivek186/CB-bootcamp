class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a)
    {
        int m, n;
        m = a.size();
        n = a[0].size();

        int rs, re, cs, ce;
        rs = cs = 0;
        re = m-1;
        ce = n-1;
        vector<int> ans;
        while(rs <= re and cs <= ce)
        {
            for(int i = cs; i <= ce; i++)
            {
                ans.push_back(a[rs][i]);
            }
            rs++;
            for(int i = rs; i <= re; i++)
            {
                ans.push_back(a[i][ce]);
            }
            ce--;
            for(int i = ce; i >= cs; i--)
            {
                if(rs <= re)
                    ans.push_back(a[re][i]);
            }
            re--;
            for(int i = re; i >= rs; i--)
            {
                if(cs <= ce)
                    ans.push_back(a[i][cs]);
            }
            cs++;
        }
        return ans;
    }
};