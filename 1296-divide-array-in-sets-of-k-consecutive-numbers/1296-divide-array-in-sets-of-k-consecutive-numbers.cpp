class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0){
            return false;
        }
        map<int, int> count;
        for (int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        while (!count.empty()){
            int min = count.begin()->first;
            for (int i = min; i < min+k; i++){
                if (count.find(i) == count.end()){
                    return false;
                }
                if (--count[i] == 0){
                    count.erase(i);
                }
            }
        }
        return true;
    }
};