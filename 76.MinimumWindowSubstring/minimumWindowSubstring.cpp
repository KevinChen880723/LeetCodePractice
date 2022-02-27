#include "minimumWindowSubstring.h"
#include <unordered_map>
#include <queue>
#include <cmath>

namespace baseline{
    struct charInfo
    {
        charInfo(): num(0), posList(queue<int>()) {}
        int num;
        queue<int> posList;
    };


    string Solution::minWindow(string s, string t){
        int i, j, currentDesiredAmount = 0;
        unordered_map<char, charInfo> hashmap;
        string currentBestSubString = "";
        int shortestLenOfSubString = s.size()+1;
        int firstIdxOfSubString = -1;
        pair<int, int> *relationship = new pair<int, int>[s.size()];

        for (auto c : t){
            hashmap[c].num++;
            currentDesiredAmount++;
        }

        int last = 0;
        for (i = 0; i < s.size(); i++){
            char c = s[i];
            // If the current char is in the target string
            if (hashmap.find(c) != hashmap.end()){
                if (firstIdxOfSubString == -1) firstIdxOfSubString = i;
                // If we haven't found char `c` with the desired amount
                if (hashmap[c].num != 0){
                    // Reduce the desired amount and push c into the queue.
                    hashmap[c].num--;
                    hashmap[c].posList.push(i);
                    currentDesiredAmount--;
                    relationship[i] = make_pair<int, int>(last, s.size()-1);
                    relationship[last].second = i;
                }
                // If we already found char `c` with the desired amount
                else{
                    // The index that we want to remove from the desired sub-string
                    int frontIdx = hashmap[c].posList.front();
                    relationship[i] = make_pair<int, int>(last, s.size()-1);
                    relationship[last].second = i;
                    // Change the relationship of them
                    if (frontIdx == firstIdxOfSubString){
                        // Change the first index of the sub-string to it's next index
                        firstIdxOfSubString = relationship[frontIdx].second;
                    }
                    else{
                        relationship[relationship[frontIdx].first].second = relationship[frontIdx].second;
                        relationship[relationship[frontIdx].second].first = relationship[frontIdx].first;
                    }
                    // Pop one element from the queue, which will drop the first index of c we met
                    hashmap[c].posList.pop();
                    // Push the new index of c into the queue
                    hashmap[c].posList.push(i);
                }

                // If we find the substring with all of the chars in the target string, check the len of the substring
                if (currentDesiredAmount == 0){
                    // int minimum = s.size(), maximum = -1;
                    // for (auto info : hashmap){
                    //     minimum = min(minimum, info.second.posList.front());
                    //     maximum = i;
                    // }
                    int len = i - firstIdxOfSubString + 1;
                    if (len < shortestLenOfSubString) {
                        shortestLenOfSubString = len;
                        currentBestSubString = s.substr(firstIdxOfSubString, len);
                    }
                }
                last = i;
            }
        }
        return currentBestSubString;
    }
}

namespace twoPointers{
    string Solution::minWindow(string s, string t){
        int result_l = 0, result_len = s.size()+1;
        unordered_map<char, int> dict_target_num, dict_have_num;
        for (auto c : t){
            dict_target_num[c]++;
        }

        // Use `numDesiredUniqueChar` to note the unique char exist in `t`
        int numDesiredUniqueChar = 0;
        for (auto p : dict_target_num){
            numDesiredUniqueChar++;
        }

        int numAlreadyHaveUnique = 0;
        int l = 0, r = 0;
        bool foundDesiredSubstring = false;
        for (r = 0; r < s.size(); r++){
            dict_have_num[s[r]]++;
            // If `c` is one of the char in `t` and the number of `c` we get is equal to the desired number
            if (dict_target_num.find(s[r]) != dict_target_num.end() && dict_have_num[s[r]] == dict_target_num[s[r]]){
                numAlreadyHaveUnique++;
                while (l <= r && numAlreadyHaveUnique == numDesiredUniqueChar){
                    foundDesiredSubstring = true;
                    if (r - l + 1 < result_len){
                        result_l = l;
                        result_len = r - l + 1;
                    }
                    if (dict_target_num.find(s[l]) != dict_target_num.end()){
                        dict_have_num[s[l]]--;
                        if (dict_have_num[s[l]] < dict_target_num[s[l]]) numAlreadyHaveUnique--;
                    }
                    l++;
                }
            }
        }
        return (foundDesiredSubstring)?s.substr(result_l, result_len):string("");
    }
}