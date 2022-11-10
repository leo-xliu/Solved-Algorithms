class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curPart;
        curPart.push_back(s.substr(0,1)); 
        palpart(res, curPart, s, 1);
        return res;
    }
    
    void palpart(vector<vector<string>>& res, vector<string> curPart, string s, int ind){
        bool isPal = isPalindrome(*curPart.rbegin());
        if (ind == s.length()){
            if (isPal) res.push_back(curPart);
            return;
        }
        
        curPart.rbegin()->push_back(s[ind]);
        palpart(res, curPart, s, ind+1);
        curPart.rbegin()->pop_back();
        
        if (isPal){
            curPart.push_back(s.substr(ind, 1));
            palpart(res, curPart, s, ind+1);
            curPart.pop_back();
        }
    }
    
    bool isPalindrome(string s){
        int l(0), r(s.length()-1);
        while (l < r){
            if (s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }
};