#include "spiralMatrix.h"

void addEdgePoints2List(vector<vector<int> >& matrix, vector<int> &result){
    int i, j;
    
    // Add the first row
    if (matrix.size() >= 1)
        for (i = 0; i < matrix[0].size(); i++) result.push_back(matrix[0][i]);

    // Add the last col
    if (matrix.size() >= 3)
        for (i = 1; i < matrix.size()-1; i++) result.push_back(matrix[i][matrix[0].size()-1]);

    // Add the last row
    if (matrix.size() >= 2)
        for (i = matrix[matrix.size()-1].size()-1; i >= 0; i--) result.push_back(matrix[matrix.size()-1][i]);

    // Add the first col
    if (matrix.size() >= 3 && matrix[0].size() >= 2)
        for (i = matrix.size()-2; i >= 1; i--) result.push_back(matrix[i][0]);

    if (matrix.size() >= 3 && matrix[0].size() >= 2){
        vector<vector<int> > matrix_in;
        for (i = 1; i < matrix.size()-1; i++){
            vector<int> m_i_1d;
            for (j = 1; j < matrix[0].size()-1; j++){
                m_i_1d.push_back(matrix[i][j]);
            }
            matrix_in.push_back(m_i_1d);
        }
        addEdgePoints2List(matrix_in, result);
    }
}

vector<int> Solution::spiralOrder(vector<vector<int> >& matrix){
    vector<int> result;
    addEdgePoints2List(matrix, result);
    return result;
}
