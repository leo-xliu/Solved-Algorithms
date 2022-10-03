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
        ListNode* node = headA;
        while (node){
            node->val *= -1;
            node = node->next;
        }
        node = headB;
        while (node){
            if (node->val < 0){
                break;
            }
            node = node->next;
        }
        ListNode* revert = headA;
            while (revert){
                revert->val *= -1;
                revert = revert->next;
            }
        return node;
    }
};

//to do this with constant space complexity, simply visit the first linked list and set each prev nodes next node to itself
//this way if we iterate through the second list, we will always land on the node where the next value is itself
//that node will be the intersection
//if there is no intersection the list will end in nullptr
//this breaks the rule of retaining original structure
//new idea: make each val negative in first list since val must be positive
//when iterating second list if we find neg value that is the intersection
//before returning make all values positive again
