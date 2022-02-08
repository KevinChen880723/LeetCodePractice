#include "subString.h"
#include <vector>

namespace baseline{
    int Solution::lengthOfLongestSubstring(string s){
        string currentLongestString(""), newString("");
        int i;
        for (i = 0; i < s.size(); i++){
            string::size_type n = newString.find(s[i]);
            // If s[i] is not in newString
            if (n == string::npos){
                newString.push_back(s[i]);
                if (newString.size() > currentLongestString.size()){
                    currentLongestString = newString;
                }
            }
            // If s[i] is in newString
            else{
                if (newString.size() >= currentLongestString.size()){
                    currentLongestString = newString;
                    newString = newString.substr(n+1)+s[i];
                }
                else{
                    newString = newString.substr(n+1)+s[i];
                }
            }
        }
        return currentLongestString.size();
    }
}

namespace slidingWindow{
    int Solution::lengthOfLongestSubstring(string s) {
        vector<int> chars(128);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
}