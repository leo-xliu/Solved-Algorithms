class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> flowsPacific(n, vector<bool>(m));
        vector<vector<bool>> flowsAtlantic(n, vector<bool>(m));
        
        for (int i = 0; i < n; i++){
            dfs(heights, flowsPacific, i, 0, n, m);
            dfs(heights, flowsAtlantic, i, m-1, n, m);
        }
        for (int j = 0; j < m; j++){
            dfs(heights, flowsPacific, 0, j, n, m);
            dfs(heights, flowsAtlantic, n-1, j, n, m);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (flowsPacific[i][j] && flowsAtlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    
     void dfs(vector<vector<int>>& heights, vector<vector<bool>>& flows, int i, int j, int m, int n) {
        flows[i][j] = true;
        
        if (i > 0 && !flows[i - 1][j] && heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, flows, i - 1, j, m, n);
        }
        if (i < m - 1 && !flows[i + 1][j] && heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, flows, i + 1, j, m, n);
        }
        if (j > 0 && !flows[i][j - 1] && heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, flows, i, j - 1, m, n);
        }
        if (j < n - 1 && !flows[i][j + 1] && heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, flows, i, j + 1, m, n);
        }
    }
    
    // void dfs(vector<vector<int>> heights, vector<vector<bool>>& flows, int i, int j, int n, int m,  int prevHeight){
    //     if (i == -1 || j == -1 || i == n || j == m || heights[i][j] < prevHeight || flows[i][j]){
    //         return;
    //     }
    //     flows[i][j] = true;
    //     dfs(heights, flows, i+1, j, n, m, heights[i][j]);
    //     dfs(heights, flows, i-1, j, n, m, heights[i][j]);
    //     dfs(heights, flows, i, j+1, n, m, heights[i][j]);
    //     dfs(heights, flows, i, j-1, n, m, heights[i][j]);
    // }
};

//