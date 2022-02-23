#include "jumpGame.cpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    betterSolution::Solution solution;
    int ary[] = {5,9,3,2,1,0,2,3,3,1,0,0}, i;
    vector<int> input;
    for (i = 0; i < sizeof(ary)/sizeof(int); i++)
        input.push_back(ary[i]);
    bool result = solution.canJump(input);
    cout << result << endl;
    return 0;
}