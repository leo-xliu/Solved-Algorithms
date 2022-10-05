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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root && subRoot) return false;
        return isSubHelper(root, subRoot);
    }
    
    bool isSubHelper(TreeNode* cur, TreeNode* sub){
        if (!cur) return false; 
        if (sameTree(cur, sub)) return true;
        return (isSubtree(cur->right, sub) || isSubtree(cur->left, sub));
    }
    
    bool sameTree(TreeNode* tree1, TreeNode* tree2){
        if (!tree1 && !tree2) return true;
        if (!tree1 || !tree2) return false;
        if (tree1->val != tree2->val) return false;
        return(sameTree(tree1->left, tree2->left) && sameTree(tree1->right, tree2->right));
    }
};
