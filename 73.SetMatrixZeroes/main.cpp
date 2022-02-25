#include <vector>
#include <iostream>
#include "setMatrixZeroes.cpp"

using namespace std;

int main(){
    int ary[][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}}, y, x;
    vector<vector<int> > matrix;
    for (y = 0; y < 3; y++){
        vector<int> temp;
        for (x = 0; x < 4; x++){
            temp.push_back(ary[y][x]);
        }
        matrix.push_back(temp);
    }
    Solution solution;
    solution.setZeroes(matrix);
    return 0;
}