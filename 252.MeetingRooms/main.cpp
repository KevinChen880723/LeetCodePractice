#include "Solution.cpp"
#include <iostream>

int main() {
    vector<vector<int> > intervals;
    int testData[][2] = {{15,20},{0,2},{5,13}};
    for (int i = 0; i < 3; i++) {
        vector<int> temp;
        temp.push_back(testData[i][0]);
        temp.push_back(testData[i][1]);
        intervals.push_back(temp);
    }
    sorting::Solution solution;
    cout << solution.canAttendMeetings(intervals) << endl;
    return 0;
}