#include <string>

using namespace std;

typedef struct node
{
    char data;
    node *ptr;
    node(): data(0), ptr(nullptr) {}
    node(char d): data(d), ptr(nullptr) {}
    node(char d, node *p): data(d), ptr(p) {}
}node;


class Stack{
public:
    Stack(): top(nullptr){}
    bool isEmpty() const{
        if (top == nullptr) return true;
        else return false;
    }
    void push(char d){
        node *newNode = new node(d, top);
        top = newNode;
    }
    char pop(char source){
        char topData = top->data, target;
        
        switch (source){
            case ')': target = '('; break;
            case ']': target = '['; break;
            case '}': target = '{'; break;
        }

        if (topData == target){
            node *nodeToRemove = top;
            top = top->ptr;
            delete nodeToRemove;
        }
        else{
            topData = 'F';
        }
        return topData;
    }
private:
    node *top;
};

class Solution {
public:
    Solution() {}
    bool isValid(string s);
};