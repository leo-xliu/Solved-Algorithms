class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res; 
        int i = 0, j = 0;
        int n = firstList.size(), m = secondList.size();
        while (i < n && j < m){
            if (firstList[i][1] < secondList[j][0]){
                i++;
                continue;
            }
            if (secondList[j][1] < firstList[i][0]){
                j++;
                continue;
            }
            res.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            (firstList[i][1] < secondList[j][1]) ? (i++) : (j++);
        }
        return res;
    }
};