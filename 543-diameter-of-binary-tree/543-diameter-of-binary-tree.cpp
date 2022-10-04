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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0; 
        diameterHelper(root, res);
        return res;
    }
    int diameterHelper(TreeNode* cur, int &res){
        if (!cur->right && !cur->left) return 0;
        int left = (cur->right) ? (diameterHelper(cur->right, res)+1) : (0);
        int right = (cur->left) ? (diameterHelper(cur->left, res)+1) : (0);
        int curmax = left+right;
        res = max(res, curmax);
        int temp = (left < right) ? (right) : (left);
        return temp;
    }
};

//keep a global max
//each node we visit will calculate the maximum length through itself (left child length + 1 + right child length) and its two children then return the child with the longer path+1
//base case: both children are node pointers so max is 1 and length is 1