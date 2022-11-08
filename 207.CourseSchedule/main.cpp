#include "Solution.cpp"
#include <iostream>

int main() {
    int numCourses = 2;
    vector<vector<int> > prerequisites;
    int ary[][2] = {{1, 0}, {0, 1}};
    int i, j;
    for (i = 0; i < 2; i++) {
        vector<int> temp;
        temp.push_back(ary[i][0]);
        temp.push_back(ary[i][1]);
        prerequisites.push_back(temp);
    }
    Solution solution;
    bool result = solution.canFinish(numCourses, prerequisites);
    cout << result << endl;
}