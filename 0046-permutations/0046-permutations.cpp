class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& nums, int start){
        if (start == nums.size()-1){
            res.push_back(nums); 
            return;
        }
        for (int i = start; i < nums.size(); i++){
            swap(nums[i], nums[start]);
            dfs(res, nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
};