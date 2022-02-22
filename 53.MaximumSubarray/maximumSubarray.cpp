#include "maximumSubarray.h"

int Solution::maxSubArray(vector<int>& nums){
    int current = 0, max = 0, max_element=-999999999, i;
    for (i = 0; i < nums.size(); i++){
        current += nums[i];
        if (current < 0) current = 0;
        if (current > max) max = current;
        if (nums[i] > max_element) max_element = nums[i];
    }
    if (max_element < 0) max = max_element;
    return max;
}