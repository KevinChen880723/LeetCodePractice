class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int y = 1; y < nums.size(); y++) {
            int largest = 1;
            for (int x = 0; x < y; x++) {
                if (nums[y] > nums[x]) {
                    largest = max(largest, dp[x]+1);
                }
            }
            dp[y] = largest;
        }
        int largest = -10000000;
        for (int i = 0; i < dp.size(); i++) {
            largest = max(largest, dp[i]);
        }
        return largest;
    }
};