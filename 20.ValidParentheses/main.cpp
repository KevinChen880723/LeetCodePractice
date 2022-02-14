#include <iostream>
#include <string>
#include "parentheses.cpp"

using namespace std;

int main(){
    string input = "([{}]{})";
    Solution solution;
    bool result = solution.isValid(input);
    cout << "The string is: " << result << endl;

    return 0;
}