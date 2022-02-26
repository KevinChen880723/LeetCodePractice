#include "minimumWindowSubstring.cpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    Solution solution;
    string result = solution.minWindow("a", "a");
    cout << result << endl;
    return 0;
}