class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
            if (pq.size() > k){
                pq.pop();
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> resort;
        while (!pq.empty()){
            pair<int, int> temp = pq.top();
            pq.pop();
            resort.push({temp.second, temp.first});
        }
        while (!resort.empty()){
            int temp = resort.top().second;
            resort.pop();
            res.push_back(temp);
        }
        return res;
    }
};

//use a kminheap