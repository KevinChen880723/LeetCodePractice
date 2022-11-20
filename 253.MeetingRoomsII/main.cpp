#include "Solution.cpp"
#include <iostream>

int main() {
    vector<Interval> intervals;
    int testData[][2] = {{0, 70},{5, 70},{15, 70},{30, 35},{50, 70}};
    for (int i = 0; i < 5; i++) {
        Interval temp(testData[i][0], testData[i][1]);
        intervals.push_back(temp);
    }
    Solution solution;
    cout << solution.minMeetingRooms(intervals) << endl;
    return 0;
}