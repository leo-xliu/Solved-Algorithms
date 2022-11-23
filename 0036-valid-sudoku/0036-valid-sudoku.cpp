class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rmap;
        unordered_map<int, unordered_set<char>> cmap;
        unordered_map<string, unordered_set<char>> smap;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char temp = board[i][j];
                if (temp == '.'){
                    continue;
                }
                if (cmap[j].find(temp) != cmap[j].end()){
                     return false;
                }
                else {
                    cmap[j].insert(temp);
                }
                if (rmap[i].find(temp) != rmap[i].end()){
                    return false;
                }
                else {
                    rmap[i].insert(temp);
                }
                string r = to_string(i/3);
                string c = to_string(j/3);
                string rc = r + c;
                if (smap[rc].find(temp) != smap[rc].end()){
                    return false;
                }
                else {
                    smap[rc].insert(temp);
                }
            }
        }
        return true;
    }
};

//the solution using 3 arrays instead of a hash map of sets is much more elegant
//the tricky part is coming up with the array index for the square condition