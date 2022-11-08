class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curSum;
        sort(candidates.begin(), candidates.end());
        dfs(res, curSum, candidates, target, 0, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& curSum, vector<int>& candidates, int target, int sum, int start){
        if (sum == target){
            res.push_back(curSum);
        }
        if (sum > target){
            return;
        }
        for (int i = start; i < candidates.size(); i++){
            if (i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            curSum.push_back(candidates[i]);
            dfs(res, curSum, candidates, target, sum+candidates[i], i+1);
            curSum.pop_back();
        }
    }
};