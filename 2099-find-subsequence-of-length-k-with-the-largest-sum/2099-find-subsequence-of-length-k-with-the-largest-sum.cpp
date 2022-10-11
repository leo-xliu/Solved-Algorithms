class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        unordered_map<int, int> map;
        for (int i = 0; i < k; i++){
            int temp = pq.top();
            pq.pop();
            map[temp]++;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            if (map.find(nums[i]) != map.end()){
                res.push_back(nums[i]);
                if (map[nums[i]]-- == 1) map.erase(nums[i]);
            }
        }
        return res;
    }
};