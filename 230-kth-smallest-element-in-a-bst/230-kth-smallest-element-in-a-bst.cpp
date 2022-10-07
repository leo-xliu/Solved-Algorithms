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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        kSmallestHelper(root, k, res);
        return res;
    }
    void kSmallestHelper(TreeNode* cur, int& k, int& res){
        if (!cur) return;
        kSmallestHelper(cur->left, k, res);
        k--;
        if (!k) res = cur->val;
        kSmallestHelper(cur->right, k, res);
    }
    //inorder traversal
    //left 
    //cur
    //right 
};
