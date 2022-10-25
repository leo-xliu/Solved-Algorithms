/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* trailing = slow;
        while (fast != nullptr){
            fast = fast->next;
            if (fast == nullptr){
                break;
            }
            fast = fast->next;
            trailing = slow;
            slow = slow->next;
        }
        fast = slow->next;
        trailing->next = nullptr;
        TreeNode* curNode = new TreeNode(slow->val);
        if (head != slow) curNode->left = sortedListToBST(head);
        else curNode->left = nullptr;
        curNode->right = sortedListToBST(fast);
        return curNode;
    }
};