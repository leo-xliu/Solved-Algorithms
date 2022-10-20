class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int targetsum = 0;
        unordered_set<int> sums;
        for (int i = 0; i < nums.size(); i++){
            targetsum += nums[i];
        }
        if (targetsum % 2) return false;
        targetsum /= 2;
        for (int i = 0; i < nums.size(); i++){
            unordered_set<int> temp(sums.begin(), sums.end());
            if (nums[i] == targetsum) return true;
            sums.insert(nums[i]);
            for (auto p = temp.begin(); p != temp.end(); p++){
                if ((nums[i]+*p) == targetsum) return true;
                sums.insert(nums[i]+*p);
            }
        }
        return false;
    }
};