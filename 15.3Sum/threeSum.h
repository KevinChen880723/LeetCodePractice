#include <vector>

using namespace std;

namespace baseline{
    class element{
    public:
        element(): value(0), index(0) {}
        element(int i, int v): value(v), index(i) {}
        int value;
        int index;
    };

    class Solution {
    public:
        vector< vector<int> > threeSum(vector<int>& nums);
    };
}

namespace twoPointers
{
    class Solution {
    public:
        vector< vector<int> > threeSum(vector<int>& nums);
    };
} 
