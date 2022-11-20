#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
 
class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), sortByFirst);
        vector<int> meetingsHavntEnd;
        int MaxOverlapped = 0;
        for (int i = 0; i < intervals.size()-1; i++) {
            if (intervals[i].end >= intervals[i+1].start) {
                meetingsHavntEnd.push_back(intervals[i].end);
            }
            vector<int> temp;
            int currentOverlapped = 0;
            for (int j = 0; j < meetingsHavntEnd.size(); j++) {
                if (meetingsHavntEnd[j] > intervals[i+1].start) {
                    currentOverlapped++;
                    temp.push_back(meetingsHavntEnd[j]);
                }
                else { 
                    currentOverlapped--;
                }
            }
            meetingsHavntEnd = temp;
            MaxOverlapped = max(MaxOverlapped, currentOverlapped);
        }
        return MaxOverlapped+1;
    }
private:
    struct {
        bool operator() (Interval a, Interval b) {
            return a.start < b.start;
        }
    }sortByFirst;
};