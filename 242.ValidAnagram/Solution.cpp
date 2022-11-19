class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.size() != s.size()) return false;
        vector<int> map_a(26, 0);
        vector<int> map_b(26, 0);
        for (int i = 0; i < s.size(); i++) {
            map_a[s[i] - 'a']++;       
        }
        for (int i = 0; i < t.size(); i++) {
            map_b[t[i] - 'a']++;       
        }
        for (int i = 0; i < 26; i++) {
            if (map_a[i] != map_b[i]) return false;   
        }
        return true;
    }
};