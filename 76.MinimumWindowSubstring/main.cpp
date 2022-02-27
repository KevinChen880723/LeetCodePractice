#include "minimumWindowSubstring.cpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    twoPointers::Solution solution;
    string result = solution.minWindow("a", "aa");
    cout << result << endl;
    return 0;
}