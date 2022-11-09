class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (dfs(board, i, j, n, m, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, int n, int m, string word, int ind){
        if (board[i][j] != word[ind++]){
            return false;
        }
        if (ind == word.size()){
            return true;
        }
        board[i][j] = '.';
        bool up(false), right(false), down(false), left(false);
        if (i > 0) up = dfs(board, i-1, j, n, m, word, ind); 
        if (i < n-1) down = dfs(board, i+1, j, n, m, word, ind);
        if (j > 0) left = dfs(board, i, j-1, n, m, word, ind);
        if (j < m-1) right =dfs(board, i, j+1, n, m, word, ind);
        board[i][j] = word[--ind];
        return (up || right || down || left);
    }
};

//prev side
//parent: up ->1    right->2     down->3    left->4