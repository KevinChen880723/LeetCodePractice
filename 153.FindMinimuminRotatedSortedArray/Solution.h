#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, currentSmallest = INT_MAX;
        while (r > l) {
            int middle = (l + r) / 2;
            currentSmallest = min(currentSmallest, nums[middle]);
            // The breakpoint is possibly in the right part.
            if (nums[middle] > nums[r]) l = middle + 1;
            // The breakpoint is possibly in the left part.
            else if (nums[middle] < nums[l]) r = middle - 1;
            // No breakpoint. The minimum value is possibly nums[l].
            else break;
        }
        currentSmallest = min(currentSmallest, nums[l]);
        return currentSmallest;
    }
};