class Node {
public:
    int k;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache; 
    Node* left;
    Node* right;
    
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        remove(cache[key]);
        insert(cache[key]);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//design this with a hash map while keeping track of total capacity with a counter
//have the value of the hashmap be a pointer to the value node
//the value nodes will be implemented using a doubly linked list because we want to keep track of usage
//then we can have two pointers MRU (head) and LRU (tail) 
//we will always insert at the head which will be constant 
//we will always remove at the tail which will be constant
//when the get function is used, after we access the node, we must move it to the head
//we know we are always holding onto the LRU because new values are put into the head and getting values cause them to
//move to the head as well
//thus values that are not used will pile up on the tail side