class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        vector<vector<bool>> dp;
        for (int i = 0; i < size; i++){
            vector<bool> temp(size, false);
            dp.push_back(temp);
        }
        int res = 0;
        for (int i = 0; i < size; i++){
            dp[i][i] = true;
            res++;
            if (i < size-1){
                dp[i][i+1] = (s[i] == s[i+1]);
                res += dp[i][i+1];
            }
        }
        for (int i = size-3; i >= 0; i--){
            for (int j = i+2; j < size; j++){
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                res += dp[i][j];
            }
        }
        return res;
    }
};