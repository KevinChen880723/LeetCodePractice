#include "palindromic.cpp"
#include <iostream>
#include <string>

// using namespace std;

int main(){
    dynamicProgramming::Solution solution;
    std::string result, input("a");
    result = solution.longestPalindrome(input);
    std::cout << result << " is a valid answer" << std::endl;
    
    return 0;
}