class Solution {
public:
    string smallestSubsequence(string s) {
        string res;
        vector<int> count(26);
        vector<bool> contains(26);
        for (char ch : s){
            count[ch-'a']++;
        }
        for (char ch: s){
            int i = ch-'a';
            count[i]--;
            if (contains[i]){
                continue;
            }
            while (!res.empty() && res.back() > ch && count[res.back()-'a']){
                contains[res.back()-'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            contains[i] = true;
        }
        return res;
    }
};