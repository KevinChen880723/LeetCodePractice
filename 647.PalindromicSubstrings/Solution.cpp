class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector(s.size(), false));
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int y = j - i, x = j;
                if (i == 0) {
                    dp[y][x] = true;
                }
                else if (i == 1) {
                    if (s[y] == s[x]) dp[y][x] = true;
                    else dp[y][x] = false;
                }
                else {
                    dp[y][x] = dp[y+1][x-1] & (s[y] == s[x]);
                }
                if (dp[y][x] == true) count++;
            }
        }
        return count;
    }
};