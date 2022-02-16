#include "mergeKLists.h"
#include "vector"

/*
 * Every element in the heap is the header pointer of a list.
 * In the constructor, create an array for the heap.
 * The heap is constructed according to the value of the first node.
 */
class Heap{
public:
    Heap(vector<ListNode*> lists);
    void push(ListNode *head);
    ListNode* pop();
private:
    int heapEndIdx;
    int heapSize;
    ListNode **heap;
};