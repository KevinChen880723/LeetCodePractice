#include "insertInterval.h"
#include <cmath>

vector<vector<int> > Solution::insert(vector<vector<int> >& intervals, vector<int>& newInterval){
    vector<vector<int> > result;
    if (intervals.size() == 0){
        result.push_back(newInterval);
    }
    else{
        int i;
        for (i = 0; i < intervals.size(); i++){
            /*
             * No overlap with current node, current node is smaller than the new interval.
             * In this case, insert the current node to the result list.
             * Besides, if the new node is in the correct position, also insert the new node.
             */
            if (newInterval[0] > intervals[i][0] && newInterval[0] > intervals[i][1]){
                result.push_back(intervals[i]);
                // If the new node is not overlap with both of the last and next node, add the new node to the result.
                if (i+1 <= intervals.size()-1){
                    if (newInterval[1] < intervals[i+1][0] && newInterval[1] < intervals[i+1][1]) result.push_back(newInterval);
                }
                else result.push_back(newInterval);
            }
            /*
             * No overlap with current node, current node is greater than the new interval.
             * In this case, insert the current node to the result list.
             * Besides, if the new node is in the correct position, also insert the new node.
             */
            else if (newInterval[1] < intervals[i][0] && newInterval[1] < intervals[i][1]){
                // If the new node is not overlap with both of the last and next node, add the new node to the result.
                if (result.size() != 0){
                    if (newInterval[0] > result.back()[0] && newInterval[0] > result.back()[1]) result.push_back(newInterval);
                }
                else result.push_back(newInterval);
                result.push_back(intervals[i]);
            }
            /*
             * Overlap happened, merge the two intervals.
             */
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                if (i == intervals.size()-1) result.push_back(newInterval);
            }
        }
    }
    
    return result;
}