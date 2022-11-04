class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for (char letter : magazine){
            mag[letter]++;
        }
        for (char letter : ransomNote){
            if (--mag[letter] < 0){
                return false;
            }
        }
        return true;
    }
};