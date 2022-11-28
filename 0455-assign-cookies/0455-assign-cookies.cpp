class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        auto p = g.begin();
        auto q = s.begin();
        int res = 0;
        sort(p, g.end());
        sort(q, s.end());
        while (p != g.end() && q != s.end()){
            if (*p > *q){
                q++;
            }
            else{
                q++;
                p++;
                res++;
            }
        }
        return res;
    }
};