/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, int> addr;
        Node* node = head;
        Node start(0);
        Node* copy = &start;
        int i = 0;
        while (node){
            addr[node] = i;
            copy->next = new Node(node->val);
            copy = copy->next;
            node = node->next;
            i++;
        }
        copy = start.next;
        vector<int> master(i, 0);
        vector<Node*> randmap(i, NULL);
        node = head;
        for (int j = 0; j < i; j++){
            if (node->random == NULL){
                master[j] = -1;
            }
            else {
                master[j] = addr[node->random];
            }
            node = node->next;
            randmap[j] = copy;
            copy = copy->next;
        }
        copy = start.next;
        for (int j = 0; j < i; j++){
            if (master[j] == -1){
                copy->random = NULL;
            }
            else {
                copy->random = randmap[master[j]];
            }
            copy = copy->next;
        }
        return start.next;
    }
};

//keep a unordered_map of each linked list node address with its respective index

//then create array where index represents order of linked list and value equal the index random points to
//this will be the master list for the deep copy
//deep copy the linked list without the random first
//while doing this search keep track of each nodes address using an array
//iterate again and now add the random pointers using the master list that maps onto our second array


