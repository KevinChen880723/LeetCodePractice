#include <algorithm>
#include <unordered_map>
#include "twosum.h"

namespace baseline{
    vector<int> twosum::twoSum(vector<int>& nums, int target){
        int len = nums.size();
        vector<num> nums_myType(len);
        int i, j, upperBound = len-1;
        vector<int> results(2);
        sortNum sortNumObj;

        // Create a list with the index. 
        // In this way, the original index maintain after sorted the series.
        for (i = 0; i < len; i++){
            nums_myType[i].idx = i;
            nums_myType[i].n = nums[i];
        }

        sort(nums_myType.begin(), nums_myType.end(), sortNumObj);

        for (i = 0; i < len; i++){
            for (j = upperBound; j > i; j--){
                int sum = nums_myType[i].n + nums_myType[j].n;
                if (sum > target) upperBound = j;
                else if (sum == target){
                    results[0] = nums_myType[i].idx;
                    results[1] = nums_myType[j].idx;
                    return results;
                }
                else break;
            }
        }
        return results;
    }
}

namespace optimized{
    vector<int> twosum::twoSum(vector<int>& nums, int target){

        int i;
        vector<int> result(2);

        // Create a hash map
        unordered_map<int, int> nums_map;
        for (i = 0; i < nums.size(); i++){
            nums_map.insert(make_pair(nums[i], i));
        }

        // Traverse over the series and search the complement value by hash table.
        for (i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            unordered_map<int, int>::iterator search = nums_map.find(complement);
            if (search != nums_map.end() && search->second != i){
                result[0] = i;
                result[1] = search->second;
                return result;
            }
        }
        return result;
    }
}