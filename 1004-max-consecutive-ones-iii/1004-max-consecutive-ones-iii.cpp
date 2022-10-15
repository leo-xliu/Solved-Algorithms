class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l(0), r(0);
        int res = 0;
        int curmax = 0;
        int runningk = 0;
        for (; r < nums.size(); r++){
            curmax++;
            if (nums[r] == 0){
                runningk++;
            }
            if (runningk > k){
                curmax--;
                if (nums[l++] == 0){
                    runningk--;
                }
            }
            else {
                res = max(curmax, res);
            }
        }
        return res;
    }
};