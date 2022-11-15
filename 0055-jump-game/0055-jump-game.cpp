class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums[0] == 0 && nums.size() != 1){
            return false;
        }
        for (int i = nums.size()-2; i >= 0; i--){
            if (nums[i] == 0){
                int jumpsNeeded = 2;
                bool jumpable = false;
                for (int j = i-1; j >= 0; j--){
                    if (nums[j] >= jumpsNeeded){
                        i = j;
                        jumpable = true;
                        break;
                    }
                    jumpsNeeded++;
                }
                if (!jumpable){
                    return false;
                }
            }
        }
        return true;
    }
};