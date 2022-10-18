class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prevRow(1, 1);
        if (rowIndex == 0) return prevRow;
        prevRow.push_back(1);
        for (int i = 2; i <= rowIndex; i++){
            vector<int> currow(i+1, 1);
            int k = 0;
            for (int j = 1; j < i; j++){
                currow[j] = prevRow[k]+prevRow[++k];
            }
            prevRow = currow;
        }
        return prevRow;
    }
};