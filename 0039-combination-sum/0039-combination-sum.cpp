class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> curSet;
        for (int i = 0; i < candidates.size(); i++){
            dfs(res, candidates, curSet, target, 0, i);
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& candidates, vector<int>& curSet, int target, int curSum, int candidate){
        curSet.push_back(candidates[candidate]);
        curSum += candidates[candidate];
        if (curSum == target){
            res.push_back(curSet);
        }
        else if (curSum < target){
            for (int i = candidate; i < candidates.size(); i++){
                dfs(res, candidates, curSet, target, curSum, i);
            }
        }
        curSet.pop_back();
    }
};