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
        bool solved = false;
        kSmallestHelper(root, k, res, solved);
        return res;
    }
    void kSmallestHelper(TreeNode* cur, int& k, int& res, bool& solved){
        if (solved) return;
        if (!cur) return;
        kSmallestHelper(cur->left, k, res, solved);
        k--;
        if (!k) {
            res = cur->val;
            solved = true;
        }
        kSmallestHelper(cur->right, k, res, solved);
    }
    //inorder traversal
    //left 
    //cur
    //right 
};
