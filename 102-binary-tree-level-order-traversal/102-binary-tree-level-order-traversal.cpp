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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; 
        if (!root) return res;
        queue<pair<TreeNode*, int>> bfsq;
        bfsq.push({root, 0});
        while (!bfsq.empty()){
            pair<TreeNode*, int> temp = bfsq.front();
            bfsq.pop();
            if (temp.first->left) bfsq.push({temp.first->left, temp.second+1});
            if (temp.first->right) bfsq.push({temp.first->right, temp.second+1});
            if (temp.second == res.size()) res.push_back({});
            res[temp.second].push_back(temp.first->val);
        }
        return res;
    }
    
};

//breadth first search
//use a queue of pairs 
//the pair being the node and the depth
//also keep track of depth
//use depth as the vector index