class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) { 
        if (nums.size() == 0){
            return {};
        }
        vector<string> res;
        int start = 0; 
        int end = 0;
        for (int i = 1; i < nums.size()+1; i++){
            if (i == nums.size() || nums[end]+1 != nums[i]){
                string range = to_string(nums[start]);
                if (start != end){
                    range += "->"+to_string(nums[end]);
                }
                res.push_back(range);
                start = i;
                end = i;
            }
            else {
                end++;
            }
        }
        return res;
    }
};
