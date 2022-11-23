class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char, int> map;
        unordered_set<char> inRes;
        for (char ch : s){
            map[ch]++;
        }
        for (char ch: s){
            if (inRes.find(ch) == inRes.end()){
                while (res.length() != 0 && res.back() > ch && map.find(res.back()) != map.end()){
                    inRes.erase(res.back());
                    res.pop_back();
                }
                res.push_back(ch);
                inRes.insert(ch);
            }
            if (--map[ch] == 0){
                map.erase(ch);
            }
        }
        return res;
    }
};