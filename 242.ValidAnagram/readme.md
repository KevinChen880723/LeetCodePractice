# Note

這題給我們兩個字串`t`、`s`，他問我們這兩個字串是否為彼此的Anagram，也就是說他們的組成字母是不是相同，只是差在組成的順序不一樣而已。

## My Solution

由於只是要看組成的字母組合是否相同，因此我使用兩個`vector<int>(26, 0)`紀錄兩個字串中各個字母出現的次數，這個過程需要`O(n)`的時間去跑過兩個字串來統計。完成以後再跑一個長度為`26`的迴圈來判斷這兩個`vector<int>`的儲存資料是否相同，如果有不同就回傳`false`。

這樣的時間複雜度為`O(n)`。

```cpp
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
```

![圖片](https://user-images.githubusercontent.com/55487740/202842246-e938ceee-eac9-4d30-b387-48c29ca4c2a8.png)
