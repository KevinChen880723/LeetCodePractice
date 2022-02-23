#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals);
private:
    void mergeInterval(const int &left, const int &right, vector<vector<int> > &result){
        vector<int> mergedInterval;
        mergedInterval.push_back(left);
        mergedInterval.push_back(right);
        result.push_back(mergedInterval);
    }

    struct SortIntervals
    {
        SortIntervals () {}
        bool operator()(const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        }
    };
};