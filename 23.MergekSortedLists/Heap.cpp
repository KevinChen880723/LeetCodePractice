#include "Heap.h"
#include <cmath>

Heap::Heap(vector<ListNode*> lists){
    int i;
    // Avoid the pointer to nullptr
    vector<ListNode*> listsWithoutNullptr;
    for (i = 0; i < lists.size(); i++)
        if (lists[i]) listsWithoutNullptr.push_back(lists[i]);

    heapEndIdx = 0;
    int *a = new int[10];
    heapSize = pow(2, (listsWithoutNullptr.size() != 0)?int(log2(listsWithoutNullptr.size())+1):0);
    heap = new ListNode*[heapSize];
    for (i = 0; i < listsWithoutNullptr.size(); i++){
        push(listsWithoutNullptr[i]);
    }
}

void Heap::push(ListNode *head){
    if (heapEndIdx < heapSize-1){
        heapEndIdx++;
        // Rearange the position of the new node
        int currentIdx = heapEndIdx;
        while (currentIdx > 1 && head->val < heap[currentIdx/2]->val){
            heap[currentIdx] = heap[currentIdx/2];
            currentIdx /= 2;
        }
        heap[currentIdx] = head;
    }
}

ListNode* Heap::pop(){
    ListNode *temp;
    // If the heap is not empty
    if (heapEndIdx >= 1){
        temp = heap[1];
        ListNode *lastNode = heap[heapEndIdx];
        heapEndIdx--;
        int currentIdx = 1;
        while (currentIdx <= heapEndIdx/2 && lastNode->val > min(heap[currentIdx*2]->val, heap[currentIdx*2+1]->val)){
            // If the left child is smaller than the right child, move the right child to the current position
            if (heap[currentIdx*2]->val < heap[currentIdx*2+1]->val) {
                heap[currentIdx] = heap[currentIdx*2];
                currentIdx = currentIdx*2;
            }
            else{
                heap[currentIdx] = heap[currentIdx*2+1];
                currentIdx = currentIdx*2+1;
            }
        }
        heap[currentIdx] = lastNode;
    }
    else {
        temp = nullptr;
    }
    return temp;
}
