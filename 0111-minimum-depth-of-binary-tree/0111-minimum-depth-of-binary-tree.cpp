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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MAX;
        preorderTraversal(root, 1, res);
        return res;
    }
    
    void preorderTraversal(TreeNode* curnode, int depth, int& res){
        if (!curnode->right && !curnode->left){
            res = min(res, depth);
        }
        if (curnode->right) preorderTraversal(curnode->right, depth+1, res);
        if (curnode->left) preorderTraversal(curnode->left, depth+1, res);
    }
};