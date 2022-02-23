#include "jumpGame.h"
#include <cmath>

namespace baseline{
    bool Solution::canJump(vector<int>& nums){
        int currentPos = 0, i;
        while (1){
            // If we can not move at the position except to the target, then it means we can not reach the target
            if (nums[currentPos] == 0 && currentPos != nums.size()-1) return false;
            // Check all of the possible next position, select the one that enables us to go to the farthest next next position
            int bestNextPos = currentPos, maxMovingStep = 0;
            for (i = 1; i <= nums[currentPos]; i++){
                if (currentPos+i >= nums.size()-1) return true;
                if (i+nums[currentPos+i] > maxMovingStep) {
                    maxMovingStep = i + nums[currentPos+i];
                    bestNextPos = currentPos + i;
                }
            }
            // Update the current position
            currentPos = bestNextPos;
            // If the new position is greater than the target, it means we can reach the target.
            if (currentPos >= nums.size()-1) return true;
        }
    }
}

namespace betterSolution{
    bool Solution::canJump(vector<int>& nums){
        int i, j, currentAvailableTarget = 0;
        for (i = 0; i < nums.size(); i++){
            if (i > currentAvailableTarget) return false;
            int targetInCurrentPos = i + nums[i];
            if (targetInCurrentPos > currentAvailableTarget)
                currentAvailableTarget = targetInCurrentPos;
            if (currentAvailableTarget >= nums.size()-1) return true;
        }
        return true;
    }
}