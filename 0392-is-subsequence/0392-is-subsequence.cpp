class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0){
            return true;
        }
        int si = 0;
        for (int ti = 0; ti < t.length(); ti++){
            if (t[ti] == s[si]){
                if (++si == s.length()){
                    return true;
                }
            }
        }
        return false;
    }
};