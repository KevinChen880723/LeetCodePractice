#include "jumpGame.cpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    baseline::Solution solution;
    int ary[] = {3, 2, 1, 0, 4}, i;
    vector<int> input;
    for (i = 0; i < sizeof(ary)/sizeof(int); i++)
        input.push_back(ary[i]);
    bool result = solution.canJump(input);
    cout << result << endl;
    return 0;
}