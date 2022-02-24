#include "insertInterval.cpp"

using namespace std;

int main(){
    Solution solution;
    int ary[][2] = {{1,2},{3,5},{6,7},{8,10},{12,16}}, i;
    vector<vector<int> > intervalSet;
    for (i = 0; i < 5; i++){
        vector<int> temp;
        temp.push_back(ary[i][0]);
        temp.push_back(ary[i][1]);
        intervalSet.push_back(temp);
    }
    vector<int> interval;
    interval.push_back(4);
    interval.push_back(8);
    vector<vector<int> > result = solution.insert(intervalSet, interval);
    ;
    return 0;
}