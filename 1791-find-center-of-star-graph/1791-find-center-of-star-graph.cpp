class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> set;
        for(int i = 0; i < edges.size(); i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            if (set.find(v1) != set.end()) return v1;
            else set.insert(v1);
            if (set.find(v2) != set.end()) return v2;
            else set.insert(v2);
        }
        return 0;
    }
};