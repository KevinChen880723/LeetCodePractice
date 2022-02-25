#include <vector>
#include <iostream>
#include "setMatrixZeroes.cpp"

using namespace std;

int main(){
    int ary[][3] = {{1, 1, 1},{1, 0, 1},{1, 1, 1}}, y, x;
    vector<vector<int> > matrix;
    for (y = 0; y < 3; y++){
        vector<int> temp;
        for (x = 0; x < 3; x++){
            temp.push_back(ary[y][x]);
        }
        matrix.push_back(temp);
    }
    efficientSpace::Solution solution;
    solution.setZeroes(matrix);
    return 0;
}