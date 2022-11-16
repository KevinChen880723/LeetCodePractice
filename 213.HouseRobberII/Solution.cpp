class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 3) return *max_element(nums.begin(), nums.end());

        vector<vector<int>> dpMap(nums.size()-1, vector(4, 0));
        dpMap[0][0] = nums[0];
        dpMap[0][2] = nums[1];

        for (int i = 1; i < nums.size(); i++) {
            if (i < nums.size()-1) {
                dpMap[i][0] = dpMap[i-1][1] + nums[i];
                dpMap[i][1] = max(dpMap[i-1][0], dpMap[i-1][1]);
            }           
            if (i > 1) {
                dpMap[i-1][2] = dpMap[i-2][3] + nums[i];
                dpMap[i-1][3] = max(dpMap[i-2][2], dpMap[i-2][3]);
            }
        }
        return *max_element(dpMap[dpMap.size()-1].begin(), dpMap[dpMap.size()-1].end());
    }
};