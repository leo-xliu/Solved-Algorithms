class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int mark = nums.size();
        for (int i = 0; i < mark; i++){
            int isMarked = (nums[i] <= mark) ? (0) : (mark);
            int ind = nums[i]-isMarked-1;
            if (nums[ind] <= mark){
                nums[ind] += mark;
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