class node {
public:
    vector<node*> pointers;
    bool isEnd;
    node() {
        isEnd = false;
        pointers = vector<node*>(26, nullptr);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        node *cur = &rootNode;
        for (int i = 0; i < word.size(); i++) {
            char newChar = word[i];
            // If the target char is not exist in the trie
            if (cur->pointers[newChar-'a'] == nullptr) {
                cur->pointers[newChar-'a'] = new node();
            }
            cur = cur->pointers[newChar-'a'];
        }
        // If current is in the last position of word
        cur->isEnd = true;
    }

    bool search_from(int from, node *root, string word) {
        node *cur = root;
        for (int i = from; i < word.size(); i++) {
            char newChar = word[i];
            if (newChar == '.') {
                for (int j = 0; j < 26; j++) {
                    if (cur->pointers[j] == nullptr) continue;
                    if (search_from(i+1, cur->pointers[j], word)) return true;
                }
                return false;
            }
            else {
                // If the target char is not exist in the trie
                if (cur->pointers[newChar-'a'] == nullptr) {
                    return false;
                }
            }
            cur = cur->pointers[newChar-'a'];
        }
        if(cur->isEnd == true) return true;
        else return false;
    }
    
    bool search(string word) {
        node *cur = &rootNode;
        return search_from(0, cur, word);
    }
private:
    node rootNode;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */