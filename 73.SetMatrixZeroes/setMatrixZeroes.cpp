#include "setMatrixZeroes.h"
#include <set>

using namespace std;

void Solution::setZeroes(vector<vector<int> >& matrix){
    set<int> zeroRowIndex, zeroColIndex;
    vector<bool> alreadyZeroedList(matrix.size(), false);
    vector<int> havntZeroedRow;

    int x, y;
    // Use set to keep the non-dupoicated col and row which should be set to zero.
    for (y = 0; y < matrix.size(); y++){
        for (x = 0; x < matrix[0].size(); x++){
            if (matrix[y][x] == 0) {
                zeroRowIndex.insert(y);
                zeroColIndex.insert(x);
            }
        }
    }

    for (int n : zeroRowIndex) {
        // Set all the elements in the row n as zero, O(n)
        matrix[n] = vector<int>(matrix[n].size(), 0);
        // Mark the row as already be zeroed
        alreadyZeroedList[n] = true;
    }
    // Create a list that stores the index which hasn't been zeroed
    for (y = 0; y < matrix.size(); y++){
        if (!alreadyZeroedList[y]) havntZeroedRow.push_back(y);
    }

    for (int n : zeroColIndex) {
        // Only zero the elements which haven't been zeroed
        for (y = 0; y < havntZeroedRow.size(); y++){
            matrix[havntZeroedRow[y]][n] = 0;
        }
    }
}