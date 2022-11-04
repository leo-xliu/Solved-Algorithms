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
    vector<int> preorder(Node* root) {
        vector<int> res; 
        preorderTrav(root, res);
        return res;
    }
    
    void preorderTrav(Node* curNode, vector<int>& res){
        if (!curNode){
            return;
        }
        res.push_back(curNode->val);
        for (int i = 0; i < curNode->children.size(); i++){
            preorderTrav(curNode->children[i], res);
        }
    }
};