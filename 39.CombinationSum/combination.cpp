#include "combination.h"
#include <algorithm>

namespace myAttemption{
    vector< vector<int> > Solution::findTwoSum(vector<int>& candidates, int rightBound, int target){
        /*
        * First, try to find the two numbers with the summation equal to the target
        * If the certain two numbers are not exist, minus the target value by the largest value.
        * 
        */
        vector<vector<int> > result;
        int left = 0, right = rightBound;
        int sum = -1, i, j;
        while (right >= left){
            sum = candidates[left] + candidates[right];
            if (sum == target) {
                vector<vector<int> > sub_result_l = findTwoSum(candidates, left-1, candidates[left]);
                vector<vector<int> > sub_result_r = findTwoSum(candidates, right-1, candidates[right]);
                vector<int> temp(1);
                temp[0] = candidates[left];
                sub_result_l.push_back(temp);
                temp[0] = candidates[right];
                sub_result_r.push_back(temp);
                for (i = 0; i < sub_result_l.size(); i++){
                    for (j = 0; j < sub_result_r.size(); j++){
                        vector<int> l(sub_result_l[i]), r(sub_result_r[j]);
                        int k;
                        for (k = 0; k < r.size(); k++)
                            l.push_back(r[k]);
                        // l.insert(l.end(), r.begin(), r.end());
                        result.push_back(l);
                    }
                }
                left++;
            }
            else if (sum < target) left++;
            else right--;
        }
        return result;
    }

    vector< vector<int> > Solution::combinationSum(vector<int>& candidates, int target){
        vector< vector<int> > result;
        sort(candidates.begin(), candidates.end());
        /*
        * First, try to find the two numbers with the summation equal to the target
        * If the certain two numbers are not exist, minus the target value by the largest value.
        * 
        */
        result = findTwoSum(candidates, candidates.size()-1, target);
        return result;
        
    }
}

namespace backtracking{
    void track(vector<int>& candidates, int startIdx, int target, vector<int> &current, vector<vector<int> > &result){
        int i;
        /*
         * If the summation of the set is equal to the target, then add the current set into the result
         * Besides, back to the last recursion and check for the next element.
         */ 
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (i = startIdx; i < candidates.size(); i++){
            /*
             * After adding the new element, if the summation is greater than the target, then prun the enumeration.
             * If the loop is break, the program will back to the last recursion and do the backtracking.
             * Because of the backtracking, the program will back to last status and try the new element.
             */
            if (candidates[i] > target) break;
            // If the program execute to this line, it means the new number is a possible element.
            target -= candidates[i];
            current.push_back(candidates[i]);
            track(candidates, i, target, current, result);
            // Execute backtracking.
            target += candidates[i];
            current.pop_back();
        }
    }

    vector< vector<int> > Solution::combinationSum(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> current;
        track(candidates, 0, target, current, result);
        return result;
    }
}