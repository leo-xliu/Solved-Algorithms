class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mono;
        unordered_map<int, int> ngreater;
        for (int cur : nums2){
            while (!mono.empty() && mono.top() < cur){
                ngreater[mono.top()] = cur;
                mono.pop();
            }
            mono.push(cur);
        }
        
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++){
            if (ngreater.find(nums1[i]) != ngreater.end()){
                res[i] = ngreater[nums1[i]];
            }
        }
        return res;
    }
};