class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n));
        int res = 0;
        dfs(board, res, 0, n);
        return res;
    }
    
    void dfs(vector<vector<bool>>& board, int &res, int row, int n){
        if (row == n){
            res++;
            return;
        }
        for (int col = 0; col < n; col++){
            if (!isValidMove(board, row, col, n)){
                continue;
            }
            board[row][col] = true;
            dfs(board, res, row+1, n);
            board[row][col] = false;
        }
    }
    
    bool isValidMove(vector<vector<bool>>& board, int i, int j, int n){
        int leftd = j-1;
        int rightd = j+1;
        for (int ind = i-1; ind >= 0; ind--){
            if (board[ind][j]){
                return false;
            }
            if (leftd >= 0 && board[ind][leftd--]){
                return false;
            }
            if (rightd < n && board[ind][rightd++]){
                return false;
            }
        }
        return true;
    }
};