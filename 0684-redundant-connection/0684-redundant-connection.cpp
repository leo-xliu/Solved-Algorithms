class UnionFind {
private: 
    vector<int> sets;
    vector<int> sizes;    
    int numComponents;

public:
    UnionFind(int n) : sets(n+1), sizes(n+1), numComponents(n){
        for (int i = 1; i < n+1; i++){
            sets[i] = i;
        }
    }
    
    //do path compression in find
    int find(int nodeA){
        int curNode = nodeA;
        while (sets[curNode] != curNode){
            curNode = sets[curNode];
        }
        return curNode;
    }
    
    bool unify(int nodeA, int nodeB){
        int parentA = find(nodeA);
        int parentB = find(nodeB);
        if (parentA == parentB){
            return false;
        }
        int sizeA = sizes[parentA];
        int sizeB = sizes[parentB];
        if (sizeA < sizeB){
            this->sets[parentA] = parentB; 
        }
        else {
            this->sets[parentB] = parentA;
        }
        numComponents--;
        return true;
    }
    
    int size(){
        return sets.size()-1;
    } 
    
    int components(){
        return numComponents;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numEdges = edges.size();
        UnionFind graph(numEdges);
        vector<int> res(2);
        for (int i = 0; i < numEdges; i++){
            vector<int> edge = edges[i];
            int nodeA = edge[0];
            int nodeB = edge[1];
            if (!graph.unify(nodeA, nodeB)){
                res[0] = nodeA;
                res[1] = nodeB;
                break;
            }
        }
        return res;
    }
};



//union find with path compression
//iterate through each edge and union the two nodes together
//if the nodes already are already connected, then that is an excessive edge