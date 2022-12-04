class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res; 
        vector<int> curPath;
        curPath.push_back(0);
        dfs(res, graph, curPath, 0, graph.size()-1);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<vector<int>>& graph, vector<int>& curPath, int i, int n){
        if (i == n){
            res.push_back(curPath);
            return;
        }
        for (int j : graph[i]){
            curPath.push_back(j);
            dfs(res, graph, curPath, j, n);
            curPath.pop_back();
        }
    }
};