#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList{
public:
    LinkedList(): first(nullptr) {}
    LinkedList(ListNode *ptr): first(ptr) {}
    LinkedList(int ary[], int len);
    void insert(int data, int pos);
    void push_back(int data);
    void remove(int pos);
    int search(int data) const;
    ListNode* getFirst() const;
private:
    ListNode *first;
};

ostream& operator <<(ostream &outStream, const LinkedList& list);
