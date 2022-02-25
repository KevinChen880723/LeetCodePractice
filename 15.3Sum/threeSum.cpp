#include "threeSum.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>

namespace baseline{
    vector< vector<int> > Solution::threeSum(vector<int>& nums){
        int i, j;
        vector< vector<int> > triplets, result;
        sort(nums.begin(), nums.end());
        
        // Initialize the hash map
        // O(n)
        unordered_map<int, vector<int> > hashMap;
        for (i = 0; i < nums.size(); i++){
            hashMap[nums[i]].push_back(i);
        }

        // O(n^2), because the most inner for-loop usually repeat only O(1) due to the property of hash map
        for (i = 0; i < nums.size(); i++){
            for (j = i+1; j < nums.size(); j++){
                int twoSum = nums[i] + nums[j];
                int complement = -twoSum;
                unordered_map<int, vector<int> >::iterator found = hashMap.find(complement); 
                // if `complement` is in the series
                if (found != hashMap.end()){
                    vector<int> list = hashMap[complement];
                    int k;
                    for (k = 0; k < list.size(); k++){
                        int index = list[k];
                        // Find the compliment with different index
                        if (index > j){
                            vector<int> triplet(3);
                            triplet[0] = nums[i];
                            triplet[1] = nums[j];
                            triplet[2] = complement;
                            triplets.push_back(triplet);
                        }
                    }
                }
            }
        }
        // Drop the duplicate triplets, this step takes the time complexity of O(n^2)
        for (i = 0; i < triplets.size(); i++){
            vector<int> t1 = triplets[i];
            bool noRepeat = true;
            for (j = i+1; j < triplets.size(); j++){
                vector<int> t2 = triplets[j];
                // triplet_1 and triplet_2 are not the same
                noRepeat = noRepeat && !(t1[0] == t2[0] && t1[1] == t2[1] && t1[2] == t2[2]);
            }
            if (noRepeat) result.push_back(t1);
        }
        return result;
    }
}

namespace twoPointers{
    vector< vector<int> > Solution::threeSum(vector<int>& nums) {
        vector< vector<int> > output;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            // Never let i refer to the same value twice to avoid duplicates.
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet(3);
                    triplet[0] = nums[i];
                    triplet[1] = nums[j];
                    triplet[2] = nums[k];
                    output.push_back(triplet);
                    ++j;
                    // Never let j refer to the same value twice (in an output) to avoid duplicates
                    while (j < k && nums[j] == nums[j-1]) ++j;
                } 
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } 
                else {
                    --k;
                }
            }
        }
        return output;
    }
}