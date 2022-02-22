#include "anagrams.h"
#include <unordered_map>

namespace bruteforce{
    vector<vector<string> > Solution::groupAnagrams(vector<string>& strs){
        vector<vector<string> > result;
        vector<vector<int> > maps;
        int i, j;
        for (i = 0; i < strs.size(); i++){
            string str = strs[i];
            if (result.size() != 0){
                bool find = false;
                /*
                 * Search over the result list
                 */
                for (j = 0; j < result.size(); j++){
                    // For each set, check whether the query string is the anagram of the first string.
                    string temp = result[j][0];
                    vector<int> map_temp = maps[j];
                    bool isAnagram = true;
                    if (str.size() != temp.size()) continue;
                    else {
                        // Sequentially check if the the char in the query string is in the first string.
                        int k;
                        for (k = 0; k < str.size(); k++){
                            // Use the concept of hash map to check whether the char is in the string (O(1)).
                            if (map_temp[str[k]-'a'] == 0) {
                                isAnagram = false;
                                break;
                            }
                            else map_temp[str[k]-'a']--;
                        }
                        // If the query string is the anagram of the first string, add the query string to the target set.
                        if (isAnagram) result[j].push_back(str);
                    }
                    // If the query string is the anagram of any set, set find to true.
                    find = find || isAnagram;
                }
                // If the query string is not the anagram of any set, create a new set.
                if (!find) {
                    vector<int> map_temp(26, 0);
                    int k;
                    for (k = 0; k < str.size(); k++)
                        map_temp[str[k]-'a']++;
                    maps.push_back(map_temp);
                    vector<string> t;
                    t.push_back(str);
                    result.push_back(t);
                }
            }
            // If the result list is empty, create a new set.
            else{
                vector<int> map_temp(26, 0);
                int k;
                for (k = 0; k < str.size(); k++)
                    map_temp[str[k]-'a']++;
                maps.push_back(map_temp);
                vector<string> temp;
                temp.push_back(str);
                result.push_back(temp);
            }
        }
        return result;
    }
}

namespace hashTable{
    vector<vector<string> > Solution::groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string> > umap;
        int i, j;
        vector<vector<string> > result;
        for (i = 0; i < strs.size(); i++){
            string str = strs[i];
            int num_map[26] = {0};
            for (j = 0; j < str.size(); j++){
                char c = str[j];
                num_map[c-'a']++;
            }
            string query("");
            for (j = 0; j < 26; j++){
                query.push_back('#');
                char c_convert = char(num_map[j]);
                query.push_back(c_convert);
            }
            unordered_map<string, vector<string> >::iterator iter =  umap.find(query);
            if (iter == umap.end()) {
                vector<string> newStr;
                newStr.push_back(str);
                umap[query] = newStr;
            }
            else umap[query].push_back(str);
        }
        
        for (const std::pair<string, vector<string> > n : umap){
            result.push_back(n.second);
        }
        return result;
    }
}