#include "threeSum.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    twoPointers::Solution solution;
    int ary[] = {-1,0,1,2,-1,-4}, i;
    vector<int> input;
    for (i = 0; i < 6; i++){
        input.push_back(ary[i]);
    }
    vector< vector<int> > result = solution.threeSum(input);
    cout << "[";
    for (i = 0; i < result.size(); i++){
        if (i > 0) cout << ", ";
        cout << "[" << result[i][0] << ", " << result[i][1] << ", " << result[i][2] << "]";
    }
    cout << "]" << endl;
    return 0;
}