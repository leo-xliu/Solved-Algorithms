class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l(0), r(0);
        int res = 0;
        long runningSum = 0;
        for (; r < nums.size(); r++){
            runningSum += nums[r];
            if ((long) nums[r]*(r-l+1)-runningSum <= k){
                res = max(res, r-l+1);
            }
            else {
                runningSum -= nums[l++];
            }
        }
        return res;
    }
};