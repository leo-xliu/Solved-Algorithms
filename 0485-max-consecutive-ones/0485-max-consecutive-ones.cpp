class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int curCount = 0;
        for (int i : nums){
            if (i){
                curCount++;
            }
            else{
                maxCount = max(maxCount, curCount);
                curCount = 0;
            }
        }
        maxCount = max(maxCount, curCount);
        return maxCount;
    }
};