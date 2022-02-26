#include "minimumWindowSubstring.h"
#include <unordered_map>
#include <queue>
#include <cmath>

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
    for (char c : t){
        hashmap[c].num++;
        currentDesiredAmount++;
    }

    for (i = 0; i < s.size(); i++){
        char c = s[i];
        // If the current char is in the target string
        if (hashmap.find(c) != hashmap.end()){
            // If we haven't found char `c` with the desired amount
            if (hashmap[c].num != 0){
                // Reduce the desired amount and push c into the queue.
                hashmap[c].num--;
                hashmap[c].posList.push(i);
                currentDesiredAmount--;
            }
            // If we already found char `c` with the desired amount
            else{
                // Pop one element from the queue, which will drop the first index of c we met
                hashmap[c].posList.pop();
                // Push the new index of c into the queue
                hashmap[c].posList.push(i);
            }

            // If we find the substring with all of the chars in the target string, check the len of the substring
            if (currentDesiredAmount == 0){
                int minimum = s.size(), maximum = -1;
                for (pair<const char, charInfo> info : hashmap){
                    minimum = min(minimum, info.second.posList.front());
                    maximum = i;
                }
                int len = maximum - minimum + 1;
                if (len < shortestLenOfSubString) {
                    shortestLenOfSubString = len;
                    currentBestSubString = s.substr(minimum, len);
                }
            }
        }
    }
    return currentBestSubString;
}