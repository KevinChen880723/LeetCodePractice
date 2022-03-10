#include <iostream>
#include <vector>
#include "longestConsecutiveSequence.cpp"
using namespace std;

int main(){
    onlineSolution::Solution solution;
    int ary[] = {0,3,7,2,5,8,4,6,0,1}, i;
    vector<int> input;
    for (i = 0; i < sizeof(ary)/sizeof(int); i++) input.push_back(ary[i]);
    int result = solution.longestConsecutive(input);
    cout << result << endl;
    return 0;
}