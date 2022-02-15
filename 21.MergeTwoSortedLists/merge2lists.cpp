#include "merge2lists.h"

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

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode *combinedFirst = nullptr, *combinedTail = nullptr;
    while (list1 || list2){
        // If both List1 and List2 are not empty
        if (list1 && list2){
            // If val in node1 is bigger than the val in node2, add node1 into combinedList
            if (list1->val < list2->val){
                moveNodeToCombinedList(&combinedFirst, &combinedTail, &list1);
            }
            else{
                moveNodeToCombinedList(&combinedFirst, &combinedTail, &list2);
            }
        }
        // If List2 is empty
        else if(list1){
            moveNodeToCombinedList(&combinedFirst, &combinedTail, &list1);
        }
        // If List1 is empty
        else{
            moveNodeToCombinedList(&combinedFirst, &combinedTail, &list2);
        }
    }
    return combinedFirst;
}