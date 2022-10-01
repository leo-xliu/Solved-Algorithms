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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cout = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* curres = nullptr;
        ListNode* reshead;
        while (cur2 || cur1){
            int val1;
            int val2;
            if (!cur1) val1 = 0;
            else val1 = cur1->val;
            if (!cur2) val2 = 0;
            else val2 = cur2->val;
            int res = val1+val2+cout;
            cout = 0;
            if (res > 9){
                res %= 10;
                cout = 1;
            }
            if (curres) {   
                curres->next = new ListNode(res, nullptr);
                curres = curres->next;
            }
            else {
                curres = new ListNode(res, nullptr);
                reshead = curres;
            }
            if (cur1) cur1 = cur1->next;
            if (cur2) cur2 = cur2->next;
        }
        if (cout == 1){
            curres->next = new ListNode(1, nullptr);
        }
        return reshead;
    }
};



