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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1){
            return head;
        }
        ListNode* cur = head;
        int length = 0;
        while (cur){
            length++;
            cur = cur->next;
        }
        int reverses = length/k;
        
        cur = head;
        ListNode* prev = nullptr;
        ListNode* next;
        ListNode* prevHead = cur;
        for (int i = 0; i < reverses; i++){
            ListNode* curHead = cur;
            for (int j = 0; j < k; j++){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            //prev holds new head 
            if (prevHead == head){
                head = prev;
            }
            else {
                prevHead->next = prev;
            }
            prevHead = curHead;  
            prev = nullptr;
        }
        if (length % k != 0){
            prevHead->next = cur;
        }
        return head;
    }
};