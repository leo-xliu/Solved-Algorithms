class UnionFind {
private: 
    vector<int> sets;
    vector<int> sizes;    
    int numComponents;

public:
    UnionFind(int n) : sets(n), sizes(n), numComponents(n){
        for (int i = 0; i < n; i++){
            sets[i] = i;
        }
    }
    
    int find(int nodeA){
        int curNode = nodeA;
        while (sets[curNode] != curNode){
            curNode = sets[curNode];
        }
        //do path compression in find
        int compressNode = nodeA;
        while (sets[compressNode] != curNode){
            int temp = sets[compressNode];
            sets[compressNode] = curNode;
            compressNode = temp;
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
            sets[parentA] = parentB; 
        }
        else {
            sets[parentB] = parentA;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind cities(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if (isConnected[i][j]){
                    cities.unify(i, j);
                }
            }
        }
        return(cities.components());
    }
};