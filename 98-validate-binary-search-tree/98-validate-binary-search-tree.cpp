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
    bool isValidBST(TreeNode* root) {
        vector<int> sorted; 
        inordertrav(root, sorted);
        for (int i = 0; i < sorted.size()-1; i++){
            if (sorted[i] >= sorted[i+1]) return false;
        }
        return true;
    }
    
    void inordertrav(TreeNode* cur, vector<int> &sorted){
        if (!cur) return;
        inordertrav(cur->left, sorted);
        sorted.push_back(cur->val);
        inordertrav(cur->right, sorted);
    }
    
    
};

// it is valid if by using an in order traversal, all the values are strictly increasing 



