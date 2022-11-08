class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int mark = nums.size();
        for (int i = 0; i < mark; i++){
            if (nums[i] <= mark){
                if (nums[nums[i]-1] <= mark){
                    nums[nums[i]-1] += mark;
                }
            }
            else {
                if (nums[nums[i]-1-mark] <= mark){
                    nums[nums[i]-1-mark] += mark;
                }
            }
        }
        for (int i = 0; i < mark; i++){
            if (nums[i] <= mark){
                res.push_back(i+1);
            }
        }
        return res;
    }
};