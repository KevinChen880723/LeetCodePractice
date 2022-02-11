#include "threeSum.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>

vector< vector<int> > Solution::threeSum(vector<int>& nums){
    int i, j;
    vector< vector<int> > triplets, result;
    sort(nums.begin(), nums.end());
    
    // Initialize the hash map
    // O(n)
    unordered_map<int, vector<element> > hashMap;
    for (i = 0; i < nums.size(); i++){
        hashMap[nums[i]].push_back(element(i, nums[i]));
    }

    // O(n^2), because the most inner for loop usually repeat only O(1) due to the property of hash map
    for (i = 0; i < nums.size(); i++){
        for (j = i+1; j < nums.size(); j++){
            int twoSum = nums[i] + nums[j];
            int complement = -twoSum;
            unordered_map<int, vector<element> >::iterator found = hashMap.find(complement); 
            // if `complement` is in the series
            if (found != hashMap.end()){
                vector<element> list = hashMap[complement];
                int k;
                for (k = 0; k < list.size(); k++){
                    int index = list[k].index;
                    int value = list[k].value;
                    // Find the value with different index which is the complement
                    if (index != i && index > j && value == complement){
                        vector<int> triplet(3);
                        triplet[0] = nums[i];
                        triplet[1] = nums[j];
                        triplet[2] = value;
                        triplets.push_back(triplet);
                    }
                }
            }
        }
    }
    // Drop the duplicate triplets
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