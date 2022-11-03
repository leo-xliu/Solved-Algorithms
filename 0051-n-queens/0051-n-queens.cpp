class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string temp(n, '.');
        vector<string> board(n, temp);
        vector<vector<string>> res;
        dfs(res, board, n, 0);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& board, int n, int row){
        if (row == n){
            res.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++){
            if (invalidMove(board, row, j, n)){
                continue;
            }
            board[row][j] = 'Q';
            dfs(res, board, n, row+1);
            board[row][j] = '.';
        }
    }
    
    bool invalidMove(vector<string>& board, int row, int j, int n){ //previous columns, UP
        int left = j;
        int right = j;
        for (int i = row-1; i >= 0; i--){
            if (board[i][j] == 'Q'){
                return true;
            }
            if (right < n-1 && board[i][++right] == 'Q'){
                return true;
            }
            if (left > 0 && board[i][--left] == 'Q'){
                return true;
            }
        }
        return false;
    }
};


//queens cannot be on same row
//queens cannot be on same column
//queens cannot be on same diagonal