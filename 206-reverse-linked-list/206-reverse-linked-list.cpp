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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* node = head;
        ListNode* next = nullptr;
        while (node != nullptr){
            ListNode *tail = new ListNode(node->val, next);
            node = node->next;
            next = tail;
        }
        return next;
    }
};