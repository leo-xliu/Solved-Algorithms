/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root){
            return 0;
        }
        int max = 1;
        findMax(root, 1, max);
        return max;
    }
    
    void findMax(Node* curNode, int curDepth, int& maxDepth){
        if (curNode->children.empty()){
            maxDepth = max(curDepth, maxDepth);
            return;
        }
        for (int i = 0; i < curNode->children.size(); i++){
            findMax(curNode->children[i], curDepth+1, maxDepth);
        }
    }
};