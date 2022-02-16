#include "mergeKLists.h"
#include "Heap.cpp"

void moveNodeToCombinedList(ListNode **combinedFirst, ListNode **combinedTail, ListNode **targetNode){
    // Add the node which is pointed by targetNode to `combinedList`
    if (!(*combinedFirst)){
        *combinedFirst = *targetNode;
        *combinedTail = *combinedFirst;
    }
    else{
        (*combinedTail)->next = *targetNode;
        *combinedTail = (*combinedTail)->next;
    }
    // Move targetNode forward
    *targetNode = (*targetNode)->next;
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists){
    Heap heap(lists);
    ListNode *combinedFirst = nullptr, *combinedTail = nullptr;
    while (1){
        ListNode *rootNode = heap.pop();
        // If the heap is empty, the program is finished
        if (!rootNode) break;
        ListNode *nextNode = rootNode->next;
        moveNodeToCombinedList(&combinedFirst, &combinedTail, &rootNode);
        /*
         * After the above function, rootNode became the next node from the original node
         * So if the next node exists, push it into the heap.
         */
        if (rootNode) heap.push(rootNode);
    }
    return combinedFirst;
}