# Note

這題跟[5. Longest Palindromic Substring](https://github.com/KevinChen880723/LeetCodePractice/tree/master/5.LongestPalindromicSubstring)很像，只是那題是要找出字串中最長的回文子字串，而這題是要數一個字串中有多少個回文子字串。

## Dynamic Programming Solution

這題的解法其實也跟第五題一樣，可以使用DP的方式來記錄各個不同長度的子字串是否為回文字串，並且由短字串延伸到長字串，因為如果已知一個短字串是回文字串，那麼如果該子字串左右兩字元相同的話，則可以擴展出新的回文子字串。當我們看到回文子字串的長度等於輸入字串長度時，接著就可以去看DP的陣列中有多少個`true`。

這樣做的時間複雜度為`O(l^2)`，`l`為字串長度，因為我們需要花(l^2)/2的時間來把DP陣列填滿。

```cpp
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
```
