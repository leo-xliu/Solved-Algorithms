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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> sum;
        dfs(res, sum, root, 0, targetSum);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& sum, TreeNode* curNode, int curSum, int targetSum){
        if (!curNode){
            return;
        }
        curSum += curNode->val;
        sum.push_back(curNode->val);
        if (curSum == targetSum && !curNode->left && !curNode->right){
            res.push_back(sum);
            sum.pop_back();
            return;
        }
        dfs(res, sum, curNode->left, curSum, targetSum);
        dfs(res, sum, curNode->right, curSum, targetSum);
        sum.pop_back();
    }
};