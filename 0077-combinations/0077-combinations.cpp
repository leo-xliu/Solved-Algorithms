class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(res, comb, 1, n, k);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& comb, int start, int n, int k){
        if (comb.size() == k){
            res.push_back(comb);
            return;
        }
        for (int i = start; i <= n; i++){
            comb.push_back(i);
            dfs(res, comb, i+1, n, k);
            comb.pop_back();
        }
    }
};