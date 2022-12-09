class Solution {
public:

    int get(vector<int> &a, unordered_map<int, int> &m, unordered_set<int> s, int i)
    {
        if(i == a.size() or s.size() == 0)  return 0;
        if(s.find(a[i]) == s.end()) return get(a, m, s, i+1);
        int op1, op2;

        //exclude
        op1 = get(a, m, s, i+1);

        //include
        op2 = m[a[i]] * a[i];
        s.erase(a[i]);
        s.erase(a[i]-1);
        s.erase(a[i]+1);
        op2 += get(a, m, s, i+1);

        return max(op1, op2);

    }

    int deleteAndEarn(vector<int>& a) 
    {
        unordered_map<int, int> m;
        unordered_set<int> s;
        int n = a.size();
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            if(s.find(a[i]) == s.end())
            {
                s.insert(a[i]);
                v.push_back(a[i]);
            }
            m[a[i]]++;
        }

        return get(v, m, s, 0);
        
    }
};