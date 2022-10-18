class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { 
        vector<bool> dp(s.length()+1, false);
        dp[s.length()] = true;
        for (int i = s.length()-1; i >= 0; i--){
            for (int j = 0; j < wordDict.size(); j++){
                string word = wordDict[j];
                int wordlen = word.length();
                if (wordlen > s.length()-i) continue;
                string posword = s.substr(i, wordlen);
                if (posword == word){
                    dp[i] = dp[i+wordlen];
                    if (dp[i]) break;
                }
            }
        }
        return dp[0];
    }
};