#include "subString.cpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    slidingWindow::Solution solution;
    string input("dvdf");
    int result;
    result = solution.lengthOfLongestSubstring(input);
    cout << "The Length of Longest Substring Without Repeating Characters is: " << result << endl;
    return 0;
}