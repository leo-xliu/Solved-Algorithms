class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.length()){
            return {};
        }
        vector<string> mapping({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        vector<string> res;
        string cur = "";
        dfs(res, mapping, digits, cur, 0);
        return res;
    }
    
    void dfs(vector<string>& res, vector<string>& mapping, string digits, string& curCom, int start){
        if (start == digits.length()){
            res.push_back(curCom);
            return;
        }
        for (int j = 0; j < mapping[digits[start]-'0'].length(); j++){
            curCom.push_back(mapping[digits[start]-'0'][j]);
            dfs(res, mapping, digits, curCom, start+1);
            curCom.pop_back();
        }
    }
};