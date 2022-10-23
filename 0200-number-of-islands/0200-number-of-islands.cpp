class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int col = grid[0].size();
        int islands = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == '1'){
                    islands++;
                    stack<pair<int, int>> land;
                    land.push({i, j});
                    grid[i][j] = '0';
                    while (!land.empty()){
                        pair<int, int> curisland = land.top();
                        land.pop();
                        int ind_i = curisland.first;
                        int ind_j = curisland.second;
                        if (ind_i > 0 && grid[ind_i-1][ind_j] == '1'){
                            grid[ind_i-1][ind_j] = '0';
                            land.push({ind_i-1, ind_j});
                        }
                        if (ind_j > 0 && grid[ind_i][ind_j-1] == '1'){
                            grid[ind_i][ind_j-1] = '0';
                            land.push({ind_i, ind_j-1});
                        }
                        if (ind_j < col-1 && grid[ind_i][ind_j+1] == '1'){
                            grid[ind_i][ind_j+1] = '0';
                            land.push({ind_i, ind_j+1});
                        }
                        if (ind_i < grid.size()-1 && grid[ind_i+1][ind_j] == '1'){
                            grid[ind_i+1][ind_j] = '0';
                            land.push({ind_i+1, ind_j});
                        }
                    }
                    
                }
            }
        }
        return islands;
    }
};

