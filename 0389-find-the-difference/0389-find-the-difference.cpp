class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> contains; 
        for (int i = 0; i < s.length(); i++){
            contains[s[i]]--;
            contains[t[i]]++;
        }
        contains[t[t.length()-1]]++;
        for (auto p = contains.begin(); p != contains.end(); p++){
            if (p->second){
               return p->first; 
            }
        }
        return -1;
    }
};