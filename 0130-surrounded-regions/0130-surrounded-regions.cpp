class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++){
            dfs(board, i, 0, n, m);
            dfs(board, i, m-1, n, m);
        }
        for (int j = 1; j < m-1; j++){
            dfs(board, 0, j, n, m);
            dfs(board, n-1, j, n, m);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'N'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m){
        if (i == -1 || j == -1 || i == n || j == m || board[i][j] != 'O'){
            return;
        }
        board[i][j] = 'N';
        dfs(board, i+1, j, n, m);
        dfs(board, i-1, j, n, m);
        dfs(board, i, j+1, n, m);
        dfs(board, i, j-1, n, m);
    }
};

