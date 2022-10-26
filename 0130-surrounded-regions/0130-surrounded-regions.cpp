class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size()-1;
        int m = board[0].size()-1;
        unordered_set<string> visited;
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (board[i][j] == 'O' && visited.find(hashIndex(i, j)) == visited.end()){
                    unordered_set<string> curVisited;
                    queue<pair<int,int>> bfs;
                    vector<pair<int,int>> setX;
                    bfs.push({i, j});
                    curVisited.insert(hashIndex(i, j));
                    while (!bfs.empty()){
                        pair<int, int> index = bfs.front();
                        bfs.pop();
                        int ith = index.first;
                        int jth = index.second;
                        if (ith == 0 || jth == 0 || ith == n || jth == m){
                            setX.clear();
                            break;
                        }
                        setX.push_back({ith, jth});
                        visited.insert(hashIndex(ith, jth));
                        if (board[ith+1][jth] != 'X' && curVisited.find(hashIndex(ith+1, jth)) == curVisited.end()){
                            curVisited.insert(hashIndex(ith+1, jth));
                            bfs.push({ith+1, jth});
                        }
                        if (board[ith-1][jth] != 'X' && curVisited.find(hashIndex(ith-1, jth)) == curVisited.end()){
                            curVisited.insert(hashIndex(ith-1, jth));
                            bfs.push({ith-1, jth});
                        }
                        if (board[ith][jth+1] != 'X' && curVisited.find(hashIndex(ith, jth+1)) == curVisited.end()){
                            curVisited.insert(hashIndex(ith, jth+1));
                            bfs.push({ith, jth+1});
                        }
                        if (board[ith][jth-1] != 'X' && curVisited.find(hashIndex(ith, jth-1)) == curVisited.end()){
                            curVisited.insert(hashIndex(ith, jth-1));
                            bfs.push({ith, jth-1});
                        }
                    }
                    for (int k = 0; k < setX.size(); k++){
                        pair<int, int> temp = setX[k];
                        board[temp.first][temp.second] = 'X';
                    }
                }
            }
        }
    }
    string hashIndex(int i, int j){
        return (to_string(i) + ' ' + to_string(j));
    }
};

//notice we never need to check corners since that is are 'cant surround' accept condition
//visited set is all O's that have been visited
//if it can be surrounded it would've been turned into an X already so it doesn't matter
//if it wasn't surrounded but was visited, then we can assume it will not be surrounded 
//if we encounter visited we can automatically assume we cannot be isolated
//use dfs