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
    bool isUnivalTree(TreeNode* root) {
        int target = root->val;
        return (isUniHelper(root, target));
    }
    bool isUniHelper(TreeNode* cur, int val){
        if (!cur) return true;
        if (cur->val != val) return false;
        return (isUniHelper(cur->left, val) && isUniHelper(cur->right, val));
    }
    
};