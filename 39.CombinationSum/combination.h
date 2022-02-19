#include <vector>

using namespace std;

namespace myAttemption{
    class Solution {
    public:
        vector< vector<int> > combinationSum(vector<int>& candidates, int target);
    private:
        vector< vector<int> > findTwoSum(vector<int>& candidates, int rightBound, int target);
    };
}

namespace backtracking{
    class Solution {
    public:
        vector< vector<int> > combinationSum(vector<int>& candidates, int target);
    };
}