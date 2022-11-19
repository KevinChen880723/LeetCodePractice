class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fromLeftMulti(nums.size(), 0), fromRightMulti(nums.size(), 0), result(nums.size(), 0);
        fromLeftMulti[0] = nums[0];
        fromRightMulti[fromRightMulti.size()-1] = nums[nums.size()-1];
        for (int i = 1; i < nums.size(); i++) {
            fromLeftMulti[i] = fromLeftMulti[i-1] * nums[i];
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            fromRightMulti[i] = fromRightMulti[i+1] * nums[i];
        }
        result[0] = fromRightMulti[1];
        result[result.size()-1] = fromLeftMulti[result.size()-2];
        for (int i = 1; i < nums.size()-1; i++) {
            result[i] = fromLeftMulti[i-1] * fromRightMulti[i+1];
        }
        return result;
    }
};