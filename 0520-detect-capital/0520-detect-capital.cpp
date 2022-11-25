class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstLetter = isupper(word[0]);
        int count = 0;
        for (int i = 0; i < word.length(); i++){
            if (!firstLetter && isupper(word[i])){
                return false;
            }
            else if (isupper(word[i])){
                count++;
            }
        }
        if (count == 1 ||count == 0 || count == word.length()){
            return true;
        }
        return false;
    }
};