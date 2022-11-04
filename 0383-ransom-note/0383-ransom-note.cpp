class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for (int i = 0; i < magazine.length(); i++){
            mag[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.length(); i++){
            if (--mag[ransomNote[i]] < 0){
                return false;
            }
        }
        return true;
    }
};