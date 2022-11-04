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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzag(res, root, 0);
        for (int i = 1; i < res.size(); i = i + 2){
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    
    void zigzag(vector<vector<int>>& res, TreeNode* curNode, int level){
        if (!curNode){
            return;
        }
        if (level >= res.size()){
            res.push_back({});
        }
        res[level].push_back(curNode->val);
        zigzag(res, curNode->left, level+1);
        zigzag(res, curNode->right, level+1);
    }    
};