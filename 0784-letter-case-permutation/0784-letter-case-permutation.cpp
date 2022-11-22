class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        int n = s.length();
        dfs(res, s, 0, n);
        return res;
    }
    
    void dfs(vector<string>& res, string& s, int start, int n){
        if (start == n){
            res.push_back(s);
            return;
        }
        char ch = s[start];
        s[start] = tolower(ch);
        dfs(res, s, start+1, n);
        if (isalpha(ch)){
            s[start] = toupper(ch);
            dfs(res, s, start+1, n);
        }
        s[start] = ch;
    }
};