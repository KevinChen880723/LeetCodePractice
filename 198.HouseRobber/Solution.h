#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int max_with_last = 0;
        int max_without_last = 0;
        for (int i: nums) {
            swap(max_with_last, max_without_last);
            max_with_last = max(max_with_last+i, max_without_last);
        }
        return max(max_without_last, max_with_last);
    }
};