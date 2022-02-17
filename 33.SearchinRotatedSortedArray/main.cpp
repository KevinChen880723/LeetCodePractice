#include "rotatedArray.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    Solution solution;
    int ary[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 1, 2, 3, 4}, i;
    vector<int> input;
    for (i = 0; i < sizeof(ary)/sizeof(int); i++) input.push_back(ary[i]);
    int result = solution.search(input, 14);
    cout << result << endl;
    return 0;
}