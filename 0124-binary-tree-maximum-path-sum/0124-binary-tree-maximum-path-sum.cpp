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
        int leftsum = maxPathSumHelper(node->left, res);
        int rightsum = maxPathSumHelper(node->right, res);
        res = max(res, leftsum+rightsum+cursum);
        int best = max(max(cursum+leftsum, cursum+rightsum), cursum);
        res = max(res, best);
        return best;
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