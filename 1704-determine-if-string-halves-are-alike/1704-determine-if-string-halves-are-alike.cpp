class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<int> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int half = s.length()/2;
        int n = s.length();
        int a = 0, b = 0;
        for (int i = 0; i < half; i++){
            if (vowels.find(s[i]) != vowels.end()){
                a++;
            }
        }
        for (int i = half; i < n; i++){
            if (vowels.find(s[i]) != vowels.end()){
                b++;
            }
        }
        return a == b;
    }
};