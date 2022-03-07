#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = prices.size()-1;
        int l_smallest = l, r_largest = r;
        int bestValue = prices[r] - prices[l];
        while (r > l) {
            if (prices[l+1]-prices[l_smallest] < prices[r_largest]-prices[r-1]) l++;
            else r--;
            l_smallest = (prices[l] < prices[l_smallest])? l: l_smallest;
            r_largest = (prices[r] > prices[r_largest])? r: r_largest;
            bestValue = max(bestValue, prices[r_largest] - prices[l_smallest]);
        }
        return bestValue;
    }
};