#include "uniquePaths.h"
#include <vector>

using namespace std;

namespace baseline{
    void findPaths(const int &m, const int &n, int current_x, int current_y, int &numPaths){
        // If the robot reachs the target
        if (current_x == n-1 && current_y == m-1){
            numPaths++;
            return;
        }
        bool atRight, atBottom;
        // If the robot reachs the right boundary
        if (current_x == n-1) atRight = true;
        else atRight = false;
        // If the robot reachs the bottom boundary
        if (current_y == m-1) atBottom = true;
        else atBottom = false;

        int i = (atRight)?1:0;
        int upperBound = (atBottom)?1:2;
        
        for (; i < upperBound; i++){
            // Go right
            if (i == 0) findPaths(m, n, current_x+1, current_y, numPaths);
            // Go down
            else findPaths(m, n, current_x, current_y+1, numPaths);
        }
    }

    int Solution::uniquePaths(int m, int n){
        int numPaths = 0;
        int current_x = 0, current_y = 0;
        findPaths(m, n, current_x, current_y, numPaths);
        return numPaths;
    }
}

namespace DP{
    int Solution::uniquePaths(int m, int n){
        int x, y;
        vector<vector<int> > LUT(m+1, vector<int>(n+1, 0));
        LUT[1][1] = 1;
        for (y = 1; y < m+1; y++){
            for (x = 1; x < n+1; x++){
                if (x == 1 && y == 1) continue;
                else LUT[y][x] = LUT[y-1][x] + LUT[y][x-1];
            }
        }
        return LUT[m][n];
    }
}