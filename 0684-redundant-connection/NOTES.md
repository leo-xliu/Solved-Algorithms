my first implementation of union find:
​
class UnionFind {
private:
vector<int> sets;
vector<int> sizes;
int numComponents;
​
public:
UnionFind(int n) : sets(n+1), sizes(n+1), numComponents(n){
for (int i = 1; i < n+1; i++){
sets[i] = i;
}
}
int find(int nodeA){
int curNode = nodeA;
while (sets[curNode] != curNode){
compresses.push_back(curNode);
curNode = sets[curNode];
}
//do path compression in find
compressNode = nodeA;
while (sets[compressNode] != curNode){
int temp = sets[compressNode];
sets[compressNode] = curNode;
compressNode = temp;
}
return curNode;