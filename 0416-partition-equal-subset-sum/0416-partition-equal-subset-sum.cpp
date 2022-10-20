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
            vector<int> temp;
            if (nums[i] == targetsum) return true;
            temp.push_back(nums[i]);
            for (auto p = sums.begin(); p != sums.end(); p++){
                if ((nums[i]+*p) == targetsum) return true;
                temp.push_back(nums[i]+*p);
            }
            for (int j = 0; j < temp.size(); j++){
                sums.insert(temp[j]);
            }
        }
        return false;
    }
};