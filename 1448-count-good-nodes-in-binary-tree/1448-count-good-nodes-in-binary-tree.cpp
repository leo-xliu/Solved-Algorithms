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
    int goodNodes(TreeNode* root) {
        return (goodNodeHelper(root, INT_MIN));
    }
    int goodNodeHelper(TreeNode* cur, int pathmax){
        if (!cur) return 0;
        if (cur->val < pathmax) return(goodNodeHelper(cur->left, pathmax)+goodNodeHelper(cur->right, pathmax));
        pathmax = max(pathmax, cur->val);
        return(goodNodeHelper(cur->left, pathmax)+goodNodeHelper(cur->right, pathmax)+1);
    }
};