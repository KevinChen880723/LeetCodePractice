# Note

這題給我們一個數列，題目希望我們找出這些數字中最多可以組成長度是多少的連續數列（這些數字在原本的數列中不一定要是連續）。

## FailedAnswer

這個方法最後失敗了，不過還是記錄一下。我的想法是使用Hash map的方式來記錄各個數字對應到的長度，當我要加入新的數字的時候，再去檢查該數字減一、加一的結果是否出現在Hash map中，如果有的話就將他們的長度串接起來。不過這麼做有個問題是：我每次修改新數字減一、加一的數字對應到的長度時，並不會一起修改到同一個連續數列中所有數字的長度，因此有可能某個範圍的右邊界有被我擴展過了，但左邊界還沒被更改，在這樣的情況下，如果之後剛好找到左邊界減一的數字，得到的就不會是最大的長度。

## SolutionFromWeb

網路上這個人的解法其實跟我差不多，不過他解決了我遇到的問題。他的方法為：我們不要修改新數字加一、減一對應到的長度，而是去修改另一端邊界的長度，範圍中間這些數字對應到的長度就不要修改。如此一來，只要我們在之後遇到已經遇過的數字就直接跳過，這樣就不會受中間還沒調整過長度的數字影響；另外，對於還沒遇過的數字，就一樣檢查加一、減一的數字，假如加一、減一的數字已經存在的話，他們就會是某個範圍的邊界，由於這些邊界對應到的長度已經被修改了，因此就會是正確的數值，之後再更新對面的邊界就好。

```cpp
int Solution::longestConsecutive(vector<int>& nums){
    unordered_map<int, int> dict;
    int *show;
    int longestLen = 0, i;
    for (int n : nums) {
        if (dict.count(n)) continue;
        int newLen = 1, l_boundary, r_boundary;
        if (dict.count(n-1) && dict.count(n+1)) {
            l_boundary = n-dict[n-1];
            r_boundary = n+dict[n+1];
            newLen = dict[n-1] + 1 + dict[n+1];
            dict[n] = dict[l_boundary] = dict[r_boundary] = newLen;
        }
        else if (dict.count(n-1) && !dict.count(n+1)) {
            l_boundary = n-dict[n-1];
            newLen = dict[n-1] + 1;
            dict[n] = dict[l_boundary] = newLen;
        }
        else if (!dict.count(n-1) && dict.count(n+1)) {
            r_boundary = n+dict[n+1];
            newLen = 1 + dict[n+1];
            dict[n] = dict[r_boundary] = newLen;
        }
        else dict[n] = newLen;
        show = (int*)(dict);
        longestLen = max(longestLen, newLen);
    }

    return longestLen;
}
```

<img width="500" alt="圖片" src="https://user-images.githubusercontent.com/55487740/157598363-e53a4737-824c-4613-b8cc-c5e9d206d73d.png">

## LeetCode Solution

這個概念非常的簡單，一開始先將輸入的數列存到Hash set中，之後去遍歷這個集合，每次都去檢查當前數字減一有沒有出現在集合中，如果沒有的話就代表他有可能會是一個連續數列的開頭，因此就往下看這個數列的長度有多長，這個部分會使用`while`迴圈來運行，不斷地檢查該數字加一是否在集合中，如果有的話則當前長度加一。

這個方法雖然使用了兩個回圈，但他的時間複雜度為`O(n)`，原因是裡面的回圈總共只會跑`n`次。以下為這個方法的Python程式：

```python
class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak
```
