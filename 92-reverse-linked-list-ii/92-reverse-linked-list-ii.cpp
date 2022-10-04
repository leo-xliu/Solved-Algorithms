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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) return head;
        int index = 1;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (index < left){
            prev = cur; 
            cur = cur->next;
            index++;
        }
        //cur now equals the first node to be reversed 
        ListNode* first = cur;
        //prev equals the node right before it
        ListNode* rprev = nullptr;
        ListNode* next = nullptr;
        while (index <= right){
            next = cur->next;
            cur->next = rprev; 
            rprev = cur; 
            cur = next;
            index++;
        }
        //next/cur equals the first node after the reversed list
        if (prev){
            prev->next = rprev;
        }
        else {
            head = rprev;
        }
        first->next = next;
        return head;
    }
};

//we can keep a counter for which position we are at in the linked list
//once we reach the position that we want to keep track of the prev value
//then begin reversing the list
//at the last reverse, keep track of the next value
//since the prev value is still pointing to the original value of the list
//we can use this to make it point to the next value we saved
//then we point our prev value to the value last reversed