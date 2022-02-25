#include "uniquePaths.cpp"
#include <iostream>

using namespace std;

int main(){
    DP::Solution solution;
    int result = solution.uniquePaths(10000, 10000);
    cout << result << endl;
    return 0;
}