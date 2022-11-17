class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++){
            if (maxReachable >= n-1){
                break;
            }
            count++;
            int max = maxReachable;
            for (int j = i; j <= max; j++){
                if (maxReachable < nums[j] + j){
                    maxReachable = nums[j] + j;
                    i = j;
                }
            }
        }
        return count;
    }
};