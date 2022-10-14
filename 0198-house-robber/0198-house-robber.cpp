class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return (max(nums[0], nums[1]));
        int prevsecond = nums[0];
        int prevfirst = nums[1];
        int cur = nums[2]+prevsecond;
        for (int i = 3; i < nums.size(); i++){
            int temp = nums[i] + max(prevsecond, prevfirst);
            prevsecond = prevfirst;
            prevfirst = cur;
            cur = temp;
        }
        return max(cur, prevfirst);
    }
};