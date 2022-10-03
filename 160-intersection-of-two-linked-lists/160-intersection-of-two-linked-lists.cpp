/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> interaddr; 
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while (l1 || l2){
            if (l1){
                if (interaddr.find(l1) != interaddr.end()) return l1;
                else {
                    interaddr.insert(l1);
                    l1 = l1->next;
                }
            }
            if (l2){
                if (interaddr.find(l2) != interaddr.end()) return l2;
                else {
                    interaddr.insert(l2);
                    l2 = l2->next;
                }
            }
        }
        return nullptr;
    }
};