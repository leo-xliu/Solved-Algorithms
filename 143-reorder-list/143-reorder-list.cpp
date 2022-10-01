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
    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head; 
        while (fast){
            fast = fast->next;
            if (!fast) break;
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* prev = nullptr;
        ListNode* cur = slow->next;
        ListNode* next = cur->next;
        slow->next = nullptr;
        while (next){
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        //cur is the head for our second linked list
        slow = head;
        next = cur;
        while (next){
            next = cur->next;
            cur->next = slow->next;
            slow->next = cur;
            slow = cur->next;
            cur = next;
        }
    }
};

//my approach
//fast and slow pointer, 
//get to half way point 
//this works for even or odd number because for even we want the greater one
//our linked list will always end on the greater one 
//middle value will have nullptr
//reverse the second half of the list using 3 pointer method
//now start from the front of the first list and the front (technically end) of the second list
//attach second list node to first nodes next node
//attach first node to second node 
//keep repeating this until we reach nullptr for second linked list