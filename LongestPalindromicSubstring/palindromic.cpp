#include <string>
#include <vector>
#include "palindromic.h"

namespace baseline{
    string Solution::longestPalindrome(string s) {
        int i;
        string currentLongestString("");

        vector<int> oddMirrorCenter, evenMirrorCenter;
        char last2Char = '!', lastChar = '!';
        for (i = 0; i < s.size(); i++){
            if (s[i] == lastChar) evenMirrorCenter.push_back(i);
            if (s[i] == last2Char) oddMirrorCenter.push_back(i-1);
            last2Char = lastChar;
            lastChar = s[i];
        }

        for (i = 0; i < oddMirrorCenter.size(); i++){
            int j = 1, center = oddMirrorCenter[i];
            string currentString;
            currentString.push_back(s[center]);
            if (currentString.size() > currentLongestString.size()) 
                currentLongestString = currentString;
            while (center-j >= 0 && center+j <= s.size()-1){
                if (s[center-j] == s[center+j]){
                    currentString.insert(currentString.begin(), s[center-j]);
                    currentString.push_back(s[center-j]);
                    j++;
                    if (currentString.size() > currentLongestString.size()) 
                        currentLongestString = currentString;
                }
                else break;
            }
        }

        for (i = 0; i < evenMirrorCenter.size(); i++){
            int j = 1, center = evenMirrorCenter[i];
            string currentString;
            currentString.insert(0, 2, s[center]);
            if (currentString.size() > currentLongestString.size()) 
                currentLongestString = currentString;
            while (center-j-1 >= 0 && center+j <= s.size()-1){
                if (s[center-j-1] == s[center+j]){
                    currentString.insert(currentString.begin(), s[center-j-1]);
                    currentString.push_back(s[center-j-1]);
                    j++;
                    if (currentString.size() > currentLongestString.size()) 
                        currentLongestString = currentString;
                }
                else break;
            }
        }

        if (currentLongestString == "") currentLongestString.push_back(s[0]);

        return currentLongestString;
    }
}