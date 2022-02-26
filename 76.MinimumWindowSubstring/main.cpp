#include "minimumWindowSubstring.cpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    Solution solution;
    string result = solution.minWindow("bba", "ab");
    cout << result << endl;
    return 0;
}