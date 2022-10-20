class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        int maxlen = 0;
        for (int i = size-1; i >= 0; i--){
            int res = 1;
            for (int j = i+1; j < size; j++){
                if (nums[i] < nums[j]){
                    res = max(res, dp[j]+1);
                }
            }
            dp[i] = res;
            maxlen = max(res, maxlen);
        }
        return maxlen;
    }
};