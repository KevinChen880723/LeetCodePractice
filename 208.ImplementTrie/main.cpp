#include "Solution.cpp"
#include <iostream>

int main() {
    int a = 10;
    int *b = &a;
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;;   // return True
    cout << obj->search("app") << endl;;     // return False
    cout << obj->startsWith("app") << endl;; // return True
    obj->insert("app");
    cout << obj->search("app") << endl;;     // return True
}