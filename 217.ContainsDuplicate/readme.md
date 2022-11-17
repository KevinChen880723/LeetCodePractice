# Note

這題很簡單，問我們一個數列中有沒有包含重複的數字。只要將輸入的`vector`轉為`unordered_set`，之後再比較兩者的大小就好，如果不重複的話兩者的大小應該會相同。

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> temp(nums.begin(), nums.end());
        return nums.size() != temp.size();
    }
};
```
