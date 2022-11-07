class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curSet;
        sort(nums.begin(), nums.end());
        dfs(res, curSet, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& curSet, vector<int>& nums, int start){
        res.push_back(curSet);
        for (int i = start; i < nums.size(); i++){
            curSet.push_back(nums[i]);
            dfs(res, curSet, nums, i+1);
            while (i < nums.size()-1 && nums[i] == nums[i+1]){
                i++;
            }
            curSet.pop_back();
        }
    }
};