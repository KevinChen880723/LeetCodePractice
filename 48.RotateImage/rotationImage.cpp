#include "rotationImage.h"

void Solution::rotate(vector<vector<int> >& matrix){
    int i, j, i_upperBound = (matrix.size()+1)/2;

    for (i = 0; i < i_upperBound; i++){
        for (j = i; j < matrix.size()-(2*i)-1+i; j++){
            int temp = matrix[matrix.size()-1-j][i];
            matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix.size()-1-j];
            matrix[matrix.size()-1-i][matrix.size()-1-j] = matrix[j][matrix.size()-1-i];
            matrix[j][matrix.size()-1-i] = matrix[i][j];
            matrix[i][j] = temp; 
        }
    }
}