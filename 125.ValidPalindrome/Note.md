# Note

這題給我們一個字串，問我們在刪除所有non-alphanumeric character（數字及英文字母以外的字元）之後，剩下的字串是不是回文字串。

## Baseline Solution

使用左右兩個指標`l`、`r`來指向頭尾的字元，之後依序往裡面走，假如遇到non-alphanumeric character就跳過。過程中不斷去比較`l`、`r`指向的字元是否相等，如果不相等的話就代表一定不是回文字串，反之如果到最後都沒問題就回傳`false`。

```cpp
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
```

![](https://i.imgur.com/EVBiSHW.png)
