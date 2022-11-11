class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        dfs(res, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int> nums, int start){
        if (start == nums.size()-1){
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++){
            if (i != start && nums[i] == nums[start]){
                continue;
            }
            swap(nums[start], nums[i]);
            dfs(res, nums, start+1);
        }
    }
};