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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        bool valid = true;
        inordertrav(root, prev, valid);
        return valid;
    }
    
    void inordertrav(TreeNode* cur, TreeNode*& prev, bool& valid){
        if (!valid) return;
        if (!cur) return;
        inordertrav(cur->left, prev, valid);
        if (prev && prev->val >= cur->val){
            valid = false;
            return;
        }
        prev = cur;
        inordertrav(cur->right, prev, valid);
    }
    
    
};

// it is valid if by using an in order traversal, all the values are strictly increasing 



