class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int first = bestrob(nums, 0, nums.size()-1);
        int second = bestrob(nums, 1, nums.size());
        return max(first, second);
    }
    
    int bestrob(vector<int> nums, int first, int last){
        int prev = 0;
        int cur = 0;
        int next = 0;
        for (int i = first; i < last; i++){
            next = max(prev+nums[i], cur);
            prev = cur;
            cur = next;
        }
        return cur;
    }
};

//this problem is essentially the same as house robber 1 but with 1 small modification 
//the only difference being that we cant have both first house and last house 
//this means our solution must include only 1 of them, or neither of them
//so to do this, we can essentinally use house robber 1 solution without the last house
//and then do the same thing without the first house
//and then take the max of the two 
