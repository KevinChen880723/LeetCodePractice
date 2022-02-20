#include "rotationImage.cpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    Solution solution;
    int ary[][3] = {{1,2,3},{4,5,6},{7,8,9}}, x, y;
    vector<vector<int> > matrix;
    for (y = 0; y < 3; y++){
        vector<int> vec;
        for (x = 0; x < 3; x++){
            vec.push_back(ary[y][x]);
        }
        matrix.push_back(vec);
    }
    solution.rotate(matrix);
    return 0;
}