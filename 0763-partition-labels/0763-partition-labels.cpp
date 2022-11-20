class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        vector<int> res;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (map.find(s[i]) == map.end()){
                map[s[i]] = i; 
            }
        }
        for (int i = 0; i < n; i++){
            if (map[s[i]] == i){
                res.push_back(1);
                continue;
            }
            else{
                int start = map[s[i]];
                int curSize = i+1;
                int addSize = 1;
                for (int j = res.size()-1; j >= 0; j--){
                    int startRan = curSize-res[j]-1;
                    int endRan = curSize-1;
                    if (start >= startRan && start <= endRan){
                        res[j] += addSize;
                        break;
                    }
                    else {
                        addSize += res[j];
                        res.pop_back();
                    }
                    curSize -= res[j];
                }
            }
        }
        return res;
    }
};