#include <iostream>
#include "linkedList.cpp"

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        // Use slow-fast pointers to separate the list into two lists (head2 stands for the slow pointer)
        if (!head->next) return;
        ListNode *fast = head;
        ListNode *head2 = head;
        ListNode *temp;
        while (fast) {
            if (!fast->next) break;
            temp = head2;
            head2 = head2->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        
        // Reverse the second list
        ListNode *prev = nullptr, *next;
        while (head2) {
            next = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = next;
        }
        head2 = prev;
        
        // Merge the two lists in the sequence set by this question.
        ListNode *p1 = head, *p2 = head2;
        while (1) {
            temp = p1->next;
            p1->next = p2;
            if (!temp) break;
            p1 = temp;
            temp = p2->next;
            p2->next = p1;
            p2 = temp;
        }
        /*
         * This is a better merging solution from the LeetCode discussion section.
         * for (p1 = head, p2 = head2; p1; ) {
         *     auto t = p1->next;
         *     p1 = p1->next = p2;
         *     p2 = t;
         * }
         */
    }
};