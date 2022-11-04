class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        int count = 0;
        for (char ch : s){
            if (++map[ch] == 2){
                count += 2;
                map.erase(ch);
            }
        }
        count += !map.empty();
        return count;
    }
};