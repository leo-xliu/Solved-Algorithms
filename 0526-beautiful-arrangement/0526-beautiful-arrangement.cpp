class Solution {
public:
    int countArrangement(int n) {
        int res = 0;
        vector<bool> check(n+1, false);
        dfs(check, res, 1, n);
        return res;
    }
    
    void dfs(vector<bool>& check, int& res, int start, int n){
        if (start == n+1){
            res++;
            return;
        }
        for (int i = 1; i <= n; i++){
            if (!check[i] && (i % start == 0 || start % i == 0)){
                check[i] = true;
                dfs(check, res, start+1, n);
                check[i] = false;
            }
        }
    }
};