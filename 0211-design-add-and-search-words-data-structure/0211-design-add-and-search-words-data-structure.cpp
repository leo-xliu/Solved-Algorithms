struct TrieNode {
    TrieNode* children[26];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* head;
    bool searchHelper(string& word, int i, TrieNode* node) {
        if (!node) {
            return false;
        }
        if (i == word.size()) {
            return node->isWord;
        }
        if (word[i] != '.') {
            return searchHelper(word, i+1, node->children[word[i]-'a']);
        }
        for (int j = 0; j < 26; j++) {
            if (searchHelper(word, i + 1, node->children[j])) {
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = head;
        for (int i = 0; i < word.size(); i++) {
            int curr = word[i] - 'a';
            if (!node->children[curr]) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */