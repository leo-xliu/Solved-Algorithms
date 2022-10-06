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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        pathHelper(root,to_string(root->val), res);
        return res;
    }
    void pathHelper(TreeNode* cur, string curpath, vector<string>& res){
        if (!cur->left && !cur->right){
            res.push_back(curpath);
            return;
        }
        if (cur->left) pathHelper(cur->left, curpath+"->"+to_string(cur->left->val), res);
        if (cur->right) pathHelper(cur->right, curpath+"->"+to_string(cur->right->val), res);
    }
};

