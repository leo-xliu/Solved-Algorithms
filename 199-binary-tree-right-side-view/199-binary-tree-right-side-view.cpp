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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; 
        if (!root) return res;
        rightviewHelper(root, res, 0);
        return res;
    }
    void rightviewHelper(TreeNode* cur, vector<int> &res, int depth){
        if (res.size() <= depth) res.push_back(cur->val);
        else res[depth] = cur->val;
        if (cur->left) rightviewHelper(cur->left, res, depth+1);
        if (cur->right) rightviewHelper(cur->right, res, depth+1);
    }
};

//keep track of depth
//depth will represent vector index
//each depth = 1 node exactly which is the right most node
//if our recursive function traverses left to right
//we just push_back if it is the first time we visit that depth
//otherwise we just keep replacing that depth with the newest possible value since that represents the right most
//we must check all cases because we are not guranteed there to be a right side 
//the only node we are guranteed to see is the root node