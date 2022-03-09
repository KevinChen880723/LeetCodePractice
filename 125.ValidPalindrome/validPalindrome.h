#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (r >= l) {
            // If the pointer points to a non-alphanumeric character
            while (!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9'))) 
                if (l < s.size()-1) l++; else return true;
            while (!((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9'))) 
                if (r > 0) r--; else return true;
            if (l < 0 || l > s.size()-1 || r < 0 || r > s.size()-1) return false;
            if (s[l] >= 'A' && s[l] <= 'Z') s[l] += 32;
            if (s[l] >= 'A' && s[r] <= 'Z') s[r] += 32;
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};