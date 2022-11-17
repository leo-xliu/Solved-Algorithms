class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curSum;
        unordered_set<int> curSet;
        dfs(res, curSum, curSet, k, 0, n, 1);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& curSum, unordered_set<int>& curSet, int k, int sum, int n, int start){
        if (k == 0 && sum == n){
            res.push_back(curSum);
            return;
        }
        for (int i = start; i <= 9; i++){
            if (curSet.find(i) != curSet.end()){
                continue;
            }
            curSet.insert(i);
            curSum.push_back(i);
            dfs(res, curSum, curSet, k-1, sum+i, n, i+1);
            curSum.pop_back();
            curSet.erase(i);
        }
    }
};