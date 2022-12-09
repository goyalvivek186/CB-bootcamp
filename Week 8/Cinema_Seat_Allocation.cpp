class Solution {
public:
    
    bool compare(vector<int> a, vector<int> b)
    {
        if(a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) 
    {
        sort(a.begin(), a.end(), compare);
        
        int ans = 0;
        int r = -1, c = -1;
        for(vector<int> v : a)
        {
            int cur_r = v[0] - 1;
            int cur_c = v[1] - 1;
            if(cur_r > r)
            {
                
            }
            else
            {
                
            }
        }
        
    }
};