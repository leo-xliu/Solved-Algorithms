class Solution {
public:
    int countArrangement(int n) {
        int res = 0;
        unordered_set<int> set;
        dfs(set, res, 1, n);
        return res;
    }
    
    void dfs(unordered_set<int>& set, int& res, int start, int n){
        if (start == n+1){
            res++;
            return;
        }
        for (int i = 1; i <= n; i++){
            if (set.find(i) != set.end()) continue;
            if (i % start == 0 || start % i == 0){
                set.insert(i);
                dfs(set, res, start+1, n);
                set.erase(i);
            }
        }
    }
};