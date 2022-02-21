#include "anagrams.h"

namespace bruteforce{
    vector<vector<string> > Solution::groupAnagrams(vector<string>& strs){
        vector<vector<string> > result;
        vector<vector<int> > maps;
        int i, j;
        for (i = 0; i < strs.size(); i++){
            string str = strs[i];
            if (result.size() != 0){
                bool find = false;
                for (j = 0; j < result.size(); j++){
                    string temp = result[j][0];
                    vector<int> map_temp = maps[j];
                    bool compareAWord = true;
                    if (str.size() != temp.size()) continue;
                    else {
                        int k;
                        for (k = 0; k < str.size(); k++){
                            if (map_temp[str[k]-'a'] == 0) {
                                compareAWord = false;
                                break;
                            }
                            else map_temp[str[k]-'a']--;
                        }
                        if (compareAWord) result[j].push_back(str);
                    }
                    find = find || compareAWord;
                }
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