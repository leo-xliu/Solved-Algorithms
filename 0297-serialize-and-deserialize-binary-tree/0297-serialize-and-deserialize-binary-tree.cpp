/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void preorderTrav(string& res, TreeNode* curNode){
        if (!curNode){
            res.push_back('n');
            res.push_back(',');
            return;
        }
        res += to_string(curNode->val);
        res.push_back(',');
        preorderTrav(res, curNode->left);
        preorderTrav(res, curNode->right);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        preorderTrav(res, root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tree;
        for (int i = 0; i < data.size(); i++){
            int size = i+1; 
            for (; size < data.size(); size++){
                if (data[size] == ','){
                    break;
                }
            }
            tree.push_back(data.substr(i, size-i));
            i = size;
        }
        int i = 0;
        TreeNode* head = buildTree(tree, i);
        return head;
    }
    
    TreeNode* buildTree(vector<string>& tree, int& curInd){
        if (tree[curInd] == "n"){
            curInd++;
            return nullptr;
        }
        TreeNode* curNode = new TreeNode(stoi(tree[curInd]));
        curInd++;
        curNode->left = buildTree(tree, curInd);
        curNode->right = buildTree(tree, curInd);
        return curNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));