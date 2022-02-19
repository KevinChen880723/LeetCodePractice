#include "combination.cpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    backtracking::Solution solution;
    vector<vector<int> > result;
    vector<int> input;
    int ary[] = {5, 6, 7, 9, 13}, i, target = 20;
    for (i = 0; i < sizeof(ary)/sizeof(int); i++)
        input.push_back(ary[i]);
    result = solution.combinationSum(input, target);
    cout << endl;
    return 0;
}