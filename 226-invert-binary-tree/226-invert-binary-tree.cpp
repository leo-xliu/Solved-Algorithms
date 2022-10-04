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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        invertTreeHelper(root);
        return root;
    }
    
    void invertTreeHelper(TreeNode* cur){
        if (!cur->right && !cur->left) return;
        TreeNode* right = cur->right;
        cur->right = cur->left;
        cur->left = right;
        if (cur->right) invertTreeHelper(cur->right);
        if (cur->left) invertTreeHelper(cur->left);
    }
};