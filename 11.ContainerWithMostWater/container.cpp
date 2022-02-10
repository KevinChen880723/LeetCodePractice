#include "container.h"
#include <vector>

using namespace std;

namespace baseline{
    int Solution::maxArea(vector<int>& height) {
        int i, j;
        int maximumSize = 0;
        for (i = 0; i < height.size(); i++){
            int currentPos = i;
            int currentHeight = height[i];
            int dis2Left = currentPos;
            int dis2Right = height.size()-currentPos-1;
            while (dis2Left != 0 || dis2Right != 0){
                if (dis2Right > dis2Left){
                    int checkPos = currentPos + dis2Right;
                    if (height[checkPos] < currentHeight) dis2Right--;
                    else {
                        int area = currentHeight * dis2Right;
                        if (area > maximumSize) maximumSize = area;
                        break;
                    }
                } 
                else{
                    int checkPos = currentPos - dis2Left;
                    if (height[checkPos] < currentHeight) dis2Left--;
                    else {
                        int area = currentHeight * dis2Left;
                        if (area > maximumSize) maximumSize = area;
                        break;
                    }
                }
            }
        }
        return maximumSize;
    }
}