#include "subString.h"

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