class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        set<string> code; 
        for (int i = 1; i < 27; i++){
            code.insert(to_string(i));
        }
        int res1 = 1;
        int res2 = 1;
        int res = 1; 
        char first = s[0];

        for (int i = 1; i < s.length(); i++){
            res = 0;
            string temp = "";
            temp += s[i];
            if (code.find(temp) != code.end()) res += res1;
            temp = first+temp;
            if (code.find(temp) != code.end()) res += res2;
            first = s[i];
            res2 = res1;
            res1 = res;
        }
        return res;
    }
};