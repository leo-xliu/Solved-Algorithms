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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        int length = 0;
        while (fast){
            length++;
            fast = fast->next;
            if (!fast) break;
            length++;
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        int half = length/2 + 1;
        int x = length-n+1;
        if (x < half) {
            x--;
            slow = head;
            prev = nullptr;
        }
        else x = x-half;
        for (int i = 0; i < x; i++){
            prev = slow;
            slow = slow->next;
        }
        if (!prev){
            head = slow->next;
            return head;
        }
        prev->next = slow->next;
        return head;
    }
};


//slow and fast pointer, find middle of the list
//double the middle for total length
//total length - x = n ----> x = length - n 
//we need to remove the xth node
//if x >= middle then we can use our current pointer
//if x < middle then we will start again from beginning

//one pass: 
//it is one pass since our first part only iterates half the list and then the second part will also only iterate half of the list as most 
