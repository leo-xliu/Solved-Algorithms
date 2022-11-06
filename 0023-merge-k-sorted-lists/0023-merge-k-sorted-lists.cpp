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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode* head; 
        for (int i = 0; i < lists.size(); i++){
            if (lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }
        if (pq.empty()){
            return nullptr;
        }
        head = pq.top().second;
        ListNode* next = pq.top().second->next;
        pq.pop();
        if (next){
            pq.push({next->val, next});
        }
        ListNode* cur = head;
        while (!pq.empty()){
            cur->next = pq.top().second;
            next = pq.top().second->next;
            pq.pop();
            if (next){
                pq.push({next->val, next});
            }
            cur = cur->next;
        }
        return head;
    }
};


//keep a k size heap?
