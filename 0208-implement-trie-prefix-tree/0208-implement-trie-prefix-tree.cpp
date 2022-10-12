struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isWord;
    TrieNode(bool _isWord) : isWord(_isWord){}
};

class Trie {
private:
    TrieNode head;
public:
    Trie() : head(TrieNode(false)){
    }
    void insert(string word) {
        TrieNode* node = &head;
        int i = 0;
        for(; i < word.length(); i++){
            if (node->children.find(word[i]) == node->children.end()){
                break;
            }
            node = node->children[word[i]];
        }
        while (i < word.length()){
            node->children[word[i]] = new TrieNode(false);
            node = node->children[word[i++]];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = &head;
        for(int i = 0; i < word.size(); i++){
            if (node->children.find(word[i]) == node->children.end()) return false;
            node = node->children[word[i]];
        }
        return(node->isWord);
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = &head;
        for(int i = 0; i < prefix.size(); i++){
            if (node->children.find(prefix[i]) == node->children.end()) return false;
            node = node->children[prefix[i]];
        }
        return true;
    }
    

};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */