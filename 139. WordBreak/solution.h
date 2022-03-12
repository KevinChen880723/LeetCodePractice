#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

namespace baseline{
    class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> set;
            for (string s : wordDict) set.insert(s);
            return wordBreak (s, 0, 0, set);
        }
        
        bool wordBreak(string s, int l, int r, unordered_set<string> &set) {
            while (r <= s.size()-1) {
                if (set.count(s.substr(l, r-l+1))) {
                    if (r < s.size()-1) {
                        if (wordBreak (s, r+1, r+1, set)) return true;
                    }
                    else return true;
                }
                r++;
            }
            return false;
        }
    };
}

namespace withMemory{
    class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> set;
            for (string s : wordDict) set.insert(s);
            return wordBreak (s, 0, 0, set);
        }
        
        bool wordBreak(string s, int l, int r, unordered_set<string> &set) {
            while (r <= s.size()-1) {
                if (set.count(s.substr(l, r-l+1))) {
                    if (r < s.size()-1) {
                        string leftSubStr = s.substr(r+1, s.size()-r);
                        if (dict.count(leftSubStr)){
                            if (dict[s.substr(l, s.size()-l)]) return true;
                        }
                        else {
                            if (wordBreak (s, r+1, r+1, set)) return dict[leftSubStr] = true;
                        }
                    }
                    else return dict[s.substr(l, s.size()-l)] = true;
                }
                r++;
            }
            return dict[s.substr(l, s.size()-l)] = false;
        }
    private:
        unordered_map<string, bool> dict;
    };
}