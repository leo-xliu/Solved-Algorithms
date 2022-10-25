/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res; 
        postOrderTraverse(root, res);
        return res;
    }
    void postOrderTraverse(TreeNode* curNode, vector<int>& res){
        if (curNode == nullptr) return;
        postOrderTraverse(curNode->left, res);
        postOrderTraverse(curNode->right, res);
        res.push_back(curNode->val);
    }
};