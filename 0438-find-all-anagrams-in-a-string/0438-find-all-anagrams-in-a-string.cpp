class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int size = p.length();
        if (s.length() < size) return res; 
        int l(0), r(0);
        vector<int> map(26);
        for (int i = 0; i < size; i++){
            map[p[i]-'a']++;
        }
        for (; r < size; r++){
            map[s[r]-'a']--;
        }
        if (isEmpty(map)){
            res.push_back(l);
        }
        for (; r < s.length(); r++){
            map[s[r]-'a']--;
            map[s[l++]-'a']++;
            if (isEmpty(map)){
                res.push_back(l);
            }
        }
        return res;
    }
    
    bool isEmpty(vector<int> map){
        for (int i = 0; i < map.size(); i++){
            if (map[i] != 0) return false;
        }
        return true;
    }
};

//window size is p