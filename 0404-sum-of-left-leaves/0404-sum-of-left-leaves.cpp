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
    int sumOfLeftLeaves(TreeNode* root) {
        return leftLeavesSum(root, 0);
    }
    
    int leftLeavesSum(TreeNode* node, int isLeft){
        if (!node->right && !node->left){
            return (node->val*isLeft);
        }
        int leftSum = 0;
        int rightSum = 0;
        if (node->left){
            leftSum = leftLeavesSum(node->left, 1);
        }
        if (node->right){
            rightSum = leftLeavesSum(node->right, 0);
        }
        return leftSum+rightSum;
    }
};