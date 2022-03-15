#include "solution.h"
#include "linkedList.cpp"

int main(){
    int ary[] = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkedList list(ary, sizeof(ary)/sizeof(int));
    Solution solution;
    solution.reorderList(list.getFirst());
    cout << list << endl;
    return 0;
}