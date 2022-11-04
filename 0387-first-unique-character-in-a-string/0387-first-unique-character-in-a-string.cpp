class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> chars;
        for (char ch : s){
            chars[ch]++;
        }
        for (int i = 0; i < s.size(); i++){
            if (chars[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};