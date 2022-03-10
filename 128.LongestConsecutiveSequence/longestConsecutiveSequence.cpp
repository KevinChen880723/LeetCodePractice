#include "longestConsecutiveSequence.h"
#include <unordered_map>
#include <algorithm>

namespace failedAns{
    int Solution::longestConsecutive(vector<int>& nums){
        // [0,3,7,2,5,8,4,6,0,1]
        unordered_map<int, int> dict;
        int longestLen = 0, i;
        for (int n : nums) {
            int newLen = 1;
            if (dict.count(n-1) && dict.count(n+1)) {
                newLen = dict[n-1] + 1 + dict[n+1];
                dict[n-dict[n-1]] = dict[n] = dict[n+dict[n+1]] = newLen;
            }
            else if (dict.count(n-1) && !dict.count(n+1)) {
                newLen = dict[n-1] + 1;
                dict[n-1] = dict[n] = newLen;
            }
            else if (!dict.count(n-1) && dict.count(n+1)) {
                newLen = 1 + dict[n+1];
                dict[n] = dict[n+1] = newLen;
            }
            else dict[n] = newLen;
            longestLen = max(longestLen, newLen);
        }

        return longestLen;
    }
}

namespace onlineSolution{
    int Solution::longestConsecutive(vector<int>& nums){
        // [0,3,7,2,5,8,4,6,0,1]
        unordered_map<int, int> dict;
        int *show;
        int longestLen = 0, i;
        for (int n : nums) {
            if (dict.count(n)) continue;
            int newLen = 1, l_boundary, r_boundary;
            if (dict.count(n-1) && dict.count(n+1)) {
                l_boundary = n-dict[n-1];
                r_boundary = n+dict[n+1];
                newLen = dict[n-1] + 1 + dict[n+1];
                dict[n] = dict[l_boundary] = dict[r_boundary] = newLen;
            }
            else if (dict.count(n-1) && !dict.count(n+1)) {
                l_boundary = n-dict[n-1];
                newLen = dict[n-1] + 1;
                dict[n] = dict[l_boundary] = newLen;
            }
            else if (!dict.count(n-1) && dict.count(n+1)) {
                r_boundary = n+dict[n+1];
                newLen = 1 + dict[n+1];
                dict[n] = dict[r_boundary] = newLen;
            }
            else dict[n] = newLen;
            show = (int*)(dict);
            longestLen = max(longestLen, newLen);
        }

        return longestLen;
    }
}