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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return pathSumHelper(root, targetSum);
    }
    bool pathSumHelper(TreeNode* curNode, int targetSum){
        targetSum -= curNode->val;
        if (!curNode->left && !curNode->right){
            return !targetSum;
        }
        bool right(false), left(false);
        if (curNode->right) right = pathSumHelper(curNode->right, targetSum);
        if (curNode->left) left = pathSumHelper(curNode->left, targetSum);
        return (right || left);
    }
};