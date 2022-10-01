class MyHashSet {
private: 
    ListNode* hashset[10000] = {nullptr};
    public:
    MyHashSet() {
    }
    
    void add(int key) {
        int hashkey = key % 10000;
        ListNode* node = hashset[hashkey];
        while (node){
            if (node->val == key) return;
            node = node->next;
        }
        if (!hashset[hashkey]) {
            hashset[hashkey] = new ListNode(key, nullptr);
        }
        else {
            ListNode* temp = hashset[hashkey];
            hashset[hashkey] = new ListNode(key, temp);
        }
    }
    
    void remove(int key) {
        int hashkey = key % 10000;
        ListNode* node = hashset[hashkey];
        if (!node) return;
        if (node->val == key){
            hashset[hashkey] = hashset[hashkey]->next;
            return;
        }
        ListNode* prev = node;
        node = node->next;
        while (node){
            if (node->val == key){
                prev->next = node->next;
                break;
            }
            prev = node;
            node = node->next;
        }
    }
    bool contains(int key) {
        int hashkey = key % 10000;
        ListNode* node = hashset[hashkey];
        while (node){
            if (node->val == key){
                return true;
            }
            node = node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */