class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int longestOR = 0;
        int l(0), r(0);
        int res = 0;
        while (r < nums.size()){
            if ((longestOR & nums[r]) == 0){
                longestOR = (longestOR | nums[r]);
                res = max(res, r-l+1);
                r++;
            }
            else {
                longestOR = longestOR & ~nums[l++];
            }
        }
        return res;
    }
};