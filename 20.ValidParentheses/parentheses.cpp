#include "parentheses.h"

bool Solution::isValid(string s){
    Stack stack;
    int i;
    for (i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack.push(s[i]);
        else{
            if (!stack.isEmpty()){
                char result = stack.pop(s[i]);
                if (result == 'F') return false;
            }
            else return false;
        }
    }
    if (stack.isEmpty()) return true;
    else return false;
}