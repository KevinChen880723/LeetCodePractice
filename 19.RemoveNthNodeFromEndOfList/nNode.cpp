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

    if (slow->next && len != n) slow->next = slow->next->next;
    if (len == n) head = head->next;

    return head;
}