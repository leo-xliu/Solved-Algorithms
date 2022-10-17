class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int res1 = 1;
        int res2 = 1;
        int res = 1; 
        for (int i = 1; i < s.length(); i++){
            res = 0;
            int ones = stoi(s.substr(i, 1));
            if (ones >= 1 && ones <= 9) res += res1;
            int tens = stoi(s.substr(i-1, 2));
            if (tens >= 10 && tens <= 26) res += res2;
            res2 = res1;
            res1 = res;
        }
        return res;
    }
};