#include "mergeIntervals.h"
#include <algorithm>

vector<vector<int> > Solution::merge(vector<vector<int> >& intervals){
    SortIntervals sortIntervals;
    sort(intervals.begin(), intervals.end(), sortIntervals);
    vector<vector<int> > result;
    int i, j, left = intervals[0][0], right = intervals[0][1];
    if (intervals.size() == 1) mergeInterval(left, right, result);
    else {
        for (i = 1; i < intervals.size(); i++){
            // If overlapped
            if (right >= intervals[i][0]) {
                if (intervals[i][0] < left) left = intervals[i][0];
                if (intervals[i][1] > right) right = intervals[i][1];
            }
            else{
                mergeInterval(left, right, result);
                left = intervals[i][0];
                right = intervals[i][1];
            }
            if (i == intervals.size()-1) mergeInterval(left, right, result);
        }
    }
    return result;
}
