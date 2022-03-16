#include <algorithm>
#include <vector>

using namespace std;

namespace mySolution{
    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int maxProduct = nums[0], negProduct = 1, posProduct = 1, i;
            for (i = 0 ; i < nums.size(); i++) {
                if (nums[i] > 0) {
                    negProduct *= nums[i];
                    posProduct = (posProduct < 0)? nums[i]: posProduct*nums[i];
                    maxProduct = max(maxProduct, max(negProduct, posProduct));
                }
                else if (nums[i] < 0) {
                    int prev_neg = negProduct;
                    negProduct = (posProduct < 0)? nums[i]: posProduct*nums[i];
                    posProduct = prev_neg * nums[i];
                    maxProduct = max(maxProduct, max(negProduct, posProduct));
                }
                else {
                    negProduct = posProduct = 1;
                    maxProduct = max(maxProduct, 0);
                }
            }
            return maxProduct;
        }
    };
}

namespace LeetCodeSolution {
    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            // Return early if input is empty
            if (nums.empty()) return 0;
            
            int best = INT_MIN;
            // Running products
            int maxProd = 1;
            int minProd = 1;
            
            for (int n: nums) {
                if (n < 0) {
                    // Swap max and min
                    swap(maxProd, minProd);
                }
                // Reset to current value if smaller or larger than it
                // (intuitively means that we start considering a new sub-array)
                maxProd = max(maxProd*n, n);
                minProd = min(minProd*n, n);
                // Update the best
                best = max(best, maxProd);
            }
            
            return best;
        }
    };
}