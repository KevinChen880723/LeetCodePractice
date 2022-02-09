#include <string>
#include <vector>
#include <iostream>
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

namespace dynamicProgramming{
    string Solution::longestPalindrome(string s){
        vector< vector<bool> > lookUpTable(s.size(), vector<bool>(s.size(), 0));
        int i, j, k;
        string longestString("");
        for (k = s.size(); k >= 1; k--){
            for (i = s.size()-k, j = 0; j < k; i++, j++){
                switch (i-j)
                {
                case 0:
                    lookUpTable[j][i] = true;
                    break;
                case 1:
                    lookUpTable[j][i] = s[i] == s[j];
                    break;
                default:
                    lookUpTable[j][i] = lookUpTable[j+1][i-1] && s[i] == s[j];
                    break;
                }
                if (lookUpTable[j][i] && (i-j+1) > longestString.size())
                    longestString = s.substr(j, i-j+1); 
            }
        }
        return longestString;
    }
}