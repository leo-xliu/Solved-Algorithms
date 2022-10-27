class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshLeft = 0;
        queue<pair<int, int>> rotten;
        queue<pair<int, int>> nextRotten;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    nextRotten.push({i, j});
                }
                else if (grid[i][j] == 1){
                    freshLeft++;
                }
            }
        }
        int minutes = 0;
        int i = 0;
        int j = 0;
        while (freshLeft != 0 && !nextRotten.empty()){
            rotten = nextRotten;
            queue<pair<int, int>> temp;
            nextRotten = temp;
            while (!rotten.empty()){
                pair<int, int> curRotten = rotten.front();
                rotten.pop();
                i = curRotten.first;
                j = curRotten.second;
                if (i < n-1 && grid[i+1][j] == 1){
                    nextRotten.push({i+1, j});
                    grid[i+1][j] = 2;
                    freshLeft--;
                }
                if (j < m-1 && grid[i][j+1] == 1){
                    nextRotten.push({i, j+1});
                    grid[i][j+1] = 2;
                    freshLeft--;
                }
                if (i > 0 && grid[i-1][j] == 1){
                    nextRotten.push({i-1, j});
                    grid[i-1][j] = 2;
                    freshLeft--;
                }
                if (j > 0 && grid[i][j-1] == 1){
                    nextRotten.push({i, j-1});
                    grid[i][j-1] = 2;
                    freshLeft--;
                }
            }
            minutes++;
        }
        if (freshLeft) return -1;
        return minutes;
    }
};

//put rotten tomatoes into a queue
//put fresh tomatoes into a vector<vector<int>>
//