#include "container.h"
#include "algorithm"

using namespace std;

class axis{
public:
    axis (): position(0), height(0){}
    axis(int p, int h){
        position = p;
        height = h;
    }
    int position;
    int height;
};

class sortAxis{
    public:
    bool operator()(axis a, axis b){
        return a.height < b.height;
    }
};

namespace baseline{
    int Solution::maxArea(vector<int>& height) {
        int i, j;
        vector<axis> axes(height.size());
        for (i = 0; i < height.size(); i++){
            axes[i] = axis(i, height[i]);
        }

        // Sort the series
        sortAxis sortObj;
        sort(axes.begin(), axes.end(), sortObj);

        int maximumSize = 0;
        for (i = 0; i < axes.size()-1; i++){
            int currentPos = axes[i].position;
            int currentHeight = axes[i].height;
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