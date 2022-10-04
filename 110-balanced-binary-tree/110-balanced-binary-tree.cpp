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
    bool isBalanced(TreeNode* root) {
        if (balancedHelper(root) == -1) return false;
        return true;
    }
    int balancedHelper(TreeNode* cur){
        if (!cur) return 0;
        int left = balancedHelper(cur->left);
        int right = balancedHelper(cur->right);
        if (left == -1 || right == -1) return -1;
        if (left <= right+1 && left >= right-1){
            int temp = (left < right) ? (right+1) : (left+1);
            return temp;
        }
        else return -1;
    }
};

//find if at each node, the children form a height-balanced tree
