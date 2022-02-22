#include "spiralMatrix.cpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    Solution solution;
    int ary[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}}, i, j;
    vector<vector<int> > input;
    for (i = 0; i < 10; i++){
        vector<int> v_i;
        for (j = 0; j < 1; j++){
            v_i.push_back(i+1);
        }
        input.push_back(v_i);
    }
    vector<int> result = solution.spiralOrder(input);
    ;
    return 0;
}