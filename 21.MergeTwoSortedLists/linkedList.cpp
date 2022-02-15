#include "linkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(int ary[], int len){
    int i;
    first = nullptr;
    for (i = 0; i < len; i++){
        push_back(ary[i]);
    }
}

void LinkedList::insert(int data, int pos){
    /*
     * First, move the head pointer to the (pos-1)-th node. (Move pos-2 times)
     * Second, insert the new node after the node.
     */
    ListNode *current = first;
    int i = 0;
    if (pos != 0){
        if (current){
            while (current->next && i < pos-1){
                current = current->next;
                i++;
            }
            if (i != pos-1) cout << "Position " << pos << " is out of the range." << endl;
            ListNode *newNode = new ListNode(data, current->next);
            current->next = newNode;
        }
        else{
            ListNode *newNode = new ListNode(data, nullptr);
            first = newNode;
        }
    }
    else{
        ListNode *newNode = new ListNode(data, current);
        first = newNode;
    }
}

void LinkedList::push_back(int data){
    ListNode *current = first;
    int i = 0;
    if (current){
        while (current->next) current = current->next;
        ListNode *newNode = new ListNode(data, nullptr);
        current->next = newNode;
    }
    else{
        ListNode *newNode = new ListNode(data, nullptr);
        first = newNode;
    }
}

void LinkedList::remove(int pos){
    ListNode *current = first, *nodeToRemove;
    int i = 0;
    while (current->next && i < pos-1){
        current = current->next;
        i++;
    }
    if (i != pos-1) cout << "Position " << pos << " is out of the range." << endl;
    nodeToRemove = current->next;
    current->next = nodeToRemove->next;
    delete nodeToRemove;
}

int LinkedList::search(int data) const{
    ListNode *current = first;
    int i = 0;
    while (current->next && current->val != data){
        current = current->next;
        i++;
    }
    return i;
}

ListNode* LinkedList::getFirst() const{
    return first;
}

ostream& operator <<(ostream &outStream, const LinkedList& list){
    ListNode *current = list.getFirst();
    while (current){
        outStream << current->val << " ";
        current = current->next;
    }
    outStream << endl;
    return outStream;
}