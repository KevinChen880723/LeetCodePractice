#include <string>

using namespace std;

class node {
public:
    node *lptr, *rptr;
    string str;
    node() {
        lptr = nullptr;
        rptr = nullptr;
        str = "";
    }
    node(node *l, node *r, string s) {
        lptr = l;
        rptr = r;
        str = s;
    }
};

class Trie {
public:
    Trie() {
        root = nullptr;
    }
    
    void insert(string word) {
        node *cur = root;
        if (root == nullptr) {
            root = new node(nullptr, nullptr, word);
        }
        else {
            while (1) {
                // If we find a correct position to put the new word, put the new node to that position
                if (word.compare(cur->str) == 0) break;
                if (word.compare(cur->str) > 0) {
                    if (cur->rptr == nullptr) {
                        cur->rptr = new node(nullptr, nullptr, word);
                        break;
                    }
                    else cur = cur->rptr;
                }
                if (word.compare(cur->str) < 0) {
                    if (cur->lptr == nullptr){
                        cur->lptr = new node(nullptr, nullptr, word);
                        break;
                    }
                    else cur = cur->lptr;
                }
            }
        }
    }
    
    bool search(string word) {
        node *cur = root;
        if (cur == nullptr) return false;
        while (1) {
            if (word.compare(cur->str) == 0) return true;
            else if (word.compare(cur->str) > 0) {
                if (cur->rptr == nullptr) return false;
                else cur = cur->rptr;
            }
            else if (word.compare(cur->str) < 0) {
                if (cur->lptr == nullptr) return false;
                else cur = cur->lptr;
            }
        }
    }
    
    bool startsWith(string prefix) {
        node *cur = root;
        if (cur == nullptr) return false;
        while (1) {
            string substr = cur->str.substr(0,prefix.length());
            if (prefix.compare(substr) == 0) return true;
            else if (prefix.compare(substr) > 0) {
                if (cur->rptr == nullptr) return false;
                else cur = cur->rptr;
            }
            else if (prefix.compare(substr) < 0) {
                if (cur->lptr == nullptr) return false;
                else cur = cur->lptr;
            }
        }
    }
private:
    node *root;
};
// ["Trie","insert","search","search","startsWith","insert","search"]
// [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */