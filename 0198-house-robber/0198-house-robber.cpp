class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int cur = 0;
        int next = 0;
        for (int i = 0; i < nums.size(); i++){
            next = max(prev+nums[i], cur);
            prev = cur;
            cur = next;
        }
        return cur;
    }
};