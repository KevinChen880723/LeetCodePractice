#include "nNode.cpp"
#include <iostream>

using namespace std;

int main(){
    int ary[] = {1,2,3,4,5}, i;
    Solution solution;
    ListNode *head = nullptr, *last = nullptr, *current;
    for (i = 0; i < sizeof(ary)/sizeof(int); i++){
        ListNode *newNode = new ListNode(ary[i]);
        if (i == 0){
            head = newNode;
            last = newNode;
        }
        else{
            last->next = newNode;
            last = last->next;
        }
    }

    head = solution.removeNthFromEnd(head, 5);

    current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}