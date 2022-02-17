#include "rotatedArray.h"

int BinarySearch(vector<int>& nums, int left, int right, const int &target){
    int index = -1;
    while (right - left >= 0){
        int middle = (right + left) / 2;
        if (nums[middle] == target) {
            index = middle;
            break;
        }
        else{
            // The threshold is in the left part
            if (nums[left] > nums[middle]){
                if(target > nums[middle] && target <= nums[right]) 
                    left = middle+1;
                else 
                    right = middle-1;
            }
            // The threshold is in the right part
            else if (nums[right] < nums[middle]){ 
                if(target < nums[middle] && target >= nums[left]) 
                    right = middle-1;
                else 
                    left = middle+1;
            }
            // The threshold is not in both of the left and right parts
            else{
                if (target < nums[middle])
                    right = middle-1;
                else
                    left = middle+1;
            }
        }
    }
    return index;
}

int Solution::search(vector<int>& nums, int target){
    int left = 0, right = nums.size()-1;
    int result = BinarySearch(nums, left, right, target);
    return result;
}