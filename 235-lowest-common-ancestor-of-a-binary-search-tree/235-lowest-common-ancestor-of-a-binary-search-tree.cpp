/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;
        TreeNode* cur = root;
        while (cur){
            if (cur->val == pval || cur->val == qval) return cur;
            if ((cur->val > pval && cur->val < qval) || (cur->val < pval && cur->val > qval)) return cur;
            if (cur->val > pval && cur->val > qval){
                cur = cur->left;
            }
            else cur = cur->right;
        }
        return cur;
    }
};


//it is a BST
//and the values are unique
//unique values tell us that there can only be 1 LCA 
//there will not be possible other ones
//we do not need to check for lowest node as we will noly need to check for first and only occurence