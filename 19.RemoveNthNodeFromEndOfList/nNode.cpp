#include "nNode.h"

ListNode* Solution::removeNthFromEnd(ListNode* head, int n){
    ListNode *slow = head, *fast = head;
    int i, len = 1;

    // Let the faster pointer lead the slower pointer by `n` points.
    for (i = 0; i < n; i++){
        if (fast->next) {
            fast = fast->next;  
            len++;
        }
    }

    // Move two pointers until the faster pointer arrive the end of the list.
    while (fast->next){
        fast = fast->next;
        slow = slow->next;
        len++;
    }

    // If the node we want to remove is the first node, let pointer `head` point to the second node.
    if (len == n) head = head->next;
    else{
        // Else, due to the slower pointer is already in the previous node of the target node, so just by-pass the target node.
        if (slow->next) slow->next = slow->next->next;
    }

    return head;
}