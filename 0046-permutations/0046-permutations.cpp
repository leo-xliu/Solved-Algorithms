class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> curSet;
        dfs(res, set, curSet);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, unordered_set<int>& set, vector<int> curSet){
        if (set.empty()){
            res.push_back(curSet); 
            return;
        }
        unordered_set<int> temp(set.begin(), set.end());
        for (auto p = temp.begin(); p != temp.end(); p++){
            set.erase(*p);
            curSet.push_back(*p);
            dfs(res, set, curSet);
            curSet.pop_back();
            set.insert(*p);
        }
    }
};