#include "linkedList.cpp"
#include "merge2lists.cpp"
#include <iostream>

using namespace std;

int main(){
    int ary1[] = {1,2,4}, ary2[] = {1,3,4};
    LinkedList list1(ary1, sizeof(ary1) / sizeof(int));
    LinkedList list2(ary2, sizeof(ary2) / sizeof(int));
    
    Solution solution;
    ListNode *first1 = list1.getFirst();
    ListNode *first2 = list2.getFirst();
    ListNode *combinedAddr = solution.mergeTwoLists(first1, first2);
    LinkedList combinedList(combinedAddr);
    cout << combinedList << endl;
}