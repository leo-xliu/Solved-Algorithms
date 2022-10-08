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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* root = buildHelper(preorder, index, inorder, 0, preorder.size()-1);
        return root;
        }
       
    TreeNode* buildHelper(vector<int>& preorder, int& i, vector<int>& inorder, int j, int k){
        if (j > k) return nullptr;
        int temp = preorder[i++];
        TreeNode* cur = new TreeNode(temp);
        int mid;
        for (int p = j; p < k; p++){
            if (inorder[p] == temp){
                mid = p;
                break;
            }
        }
        TreeNode* left = buildHelper(preorder, i, inorder, j, mid-1);
        TreeNode* right = buildHelper(preorder, i, inorder, mid+1, k);
        cur->left = left;
        cur->right = right;
        return cur;
    }

};

//preorder traversal: the root is always first
//inorder traversal: once we find the root, it partitions the tree into the left and right side
//notice what we just described is recursive
//each part of the partition forms its own subtree so the first of each half of the partition is also the "root"
//this is because preorder always counts the parent first
//inorder processes left before right so the entire array would be left before right format
//and everytime we recursively get smaller, the same idea holds as long as we obtain the parent of that half
    
    
//an important note:
//passing a pointer in as an argument will create a copy of that pointer
//the new pointer still points to the same object so modifying the object through the pointer will still modify the object in the previous environment
//notice you can choose to point by reference with pointers too
//this means we will not copy a new pointer but reference the same pointer
//the difference here is if we relocate the pointer, the original pointer will relocate too
//whereas with pass by value, if we relocate the new pointer, the original pointer will still point to the same object