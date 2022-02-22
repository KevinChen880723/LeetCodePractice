#include "maximumSubarray.cpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int ary[] = {-2,1,-3,4,-1,2,1,-5,4}, i;
    Solution solution;
    vector<int> input;
    for (i = 0; i < sizeof(ary)/sizeof(int); i++){
        input.push_back(ary[i]);
    }

    int result = solution.maxSubArray(input);
    cout << result << endl;
    
    return 0;
}