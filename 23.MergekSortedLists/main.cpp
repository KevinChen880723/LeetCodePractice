#include <iostream>
#include <cmath>
#include <vector>
#include "linkedList.cpp"
#include "mergeKLists.cpp"

using namespace std;

int main(){
    int ary1[] = {2,4,15, 6666, 8888, 9999, 1111110}, ary2[] = {3,4, 4, 6, 90}, ary3[] = {3, 4, 5, 6, 7, 22, 23, 190, 900};
    LinkedList list1(ary1, sizeof(ary1) / sizeof(int));
    LinkedList list2(ary2, sizeof(ary2) / sizeof(int));
    LinkedList list3(ary3, sizeof(ary3) / sizeof(int));
    ListNode *head1 = list1.getFirst();
    ListNode *head2 = list2.getFirst();
    ListNode *head3 = list3.getFirst();
    vector<ListNode*> input;
    input.push_back(head1);
    input.push_back(head2);
    input.push_back(head3); 

    Solution solution;
    ListNode *result = solution.mergeKLists(input);
    LinkedList resultList(result);
    cout << resultList << endl;

    return 0;
}