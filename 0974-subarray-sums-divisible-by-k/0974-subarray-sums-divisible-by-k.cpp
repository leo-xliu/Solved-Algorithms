class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remainders(k);
        int res = 0; 
        int sum = 0;
        remainders[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int remainder = sum % k;
            if (remainder < 0){
                remainder += k;
            }
            res += remainders[remainder];
            remainders[remainder]++;
        }
        return res;
    }
};


//use prefix sum remainders
//we are trying to match remainder with past remainders
//if we match, it means there are subarrays that are divisible
//take into account negative numbers
//