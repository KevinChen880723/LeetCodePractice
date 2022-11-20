#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

namespace myBaseline {
    class Solution {
    public: 
        bool canAttendMeetings(vector<vector<int> > intervals) {
            unordered_set<int> meetingTimes;
            for (int i = 0; i < intervals.size(); i++) {
                for (int j = intervals[i][0]; j <= intervals[i][1]; j++) {
                    if (meetingTimes.count(j)) return false;
                    meetingTimes.insert(j);
                }
            }
            return true;
        }
    };
};

namespace sorting {
    class Solution {
    public: 
        bool canAttendMeetings(vector<vector<int> > intervals) {
            sort(intervals.begin(), intervals.end(), sortByFirst);
            for (int i = 0; i < intervals.size()-1; i++) {
                if (intervals[i][1] >= intervals[i+1][0]) return false;
            }
            return true;
        }
    private:
        struct {
            bool operator() (vector<int> a, vector<int> b) {
                return a[0] < b[0];
            }
        }sortByFirst;
        
        
    };
};