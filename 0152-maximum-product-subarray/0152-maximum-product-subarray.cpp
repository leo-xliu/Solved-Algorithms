class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmax = nums[0]; 
        int curmin = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++){
            int temp = curmax;
            curmax = max(max(curmin*nums[i], curmax*nums[i]), nums[i]);
            curmin = min(min(curmin*nums[i], temp*nums[i]), nums[i]);
            res = max(res, curmax);
        }
        return res;
    }
};