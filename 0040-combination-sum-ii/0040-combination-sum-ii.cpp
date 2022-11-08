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
            curSum.push_back(candidates[i]);
            sum += candidates[i];
            dfs(res, curSum, candidates, target, sum, i+1);
            sum -= candidates[i];
            while (i < candidates.size()-1 && candidates[i] == candidates[i+1]){
                i++;
            }
            curSum.pop_back();
        }
    }
};