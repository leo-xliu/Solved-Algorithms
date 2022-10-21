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
    int maxPathSumHelper(TreeNode* node, int& res){
        if (!node) return 0;
        int cursum = node->val;
        int leftsum = max(maxPathSumHelper(node->left, res),0);
        int rightsum = max(maxPathSumHelper(node->right, res),0);
        res = max(res, leftsum+cursum+rightsum);
        return cursum+max(leftsum,rightsum);
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumHelper(root, res);
        return res;
    }
};


//bottom up
//break problem into subproblems of subtrees
//each parent node will see if left path sum + right path sum + itself will produce a sum greater than current max
//then it will return max(left path sum + itself, right path sum + itself, itself)
//this tells us that we must do an inorder traversal 