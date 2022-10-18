class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp(1, 1);
        res.push_back(temp);
        if (numRows == 1) return res;
        temp.push_back(1);
        res.push_back(temp);
        for (int i = 2; i < numRows; i++){
            vector<int> temp(i+1, 1);
            int k = 0;
            for (int j = 1; j < i; j++){
                temp[j] = res[i-1][k]+res[i-1][++k]; 
            }
            res.push_back(temp);
        }
        return res;
    }
};