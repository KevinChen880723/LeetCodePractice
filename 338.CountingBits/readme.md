# Note

這題給我們一個數字`n`，問我們小於這個數字的所有整數在二進制中有多少個`1`，回傳一個長度為`n+1`的數列代表從`0`到`n`的結果。

## My Solution (Baseline)

一開始看到這個題目，就想到最直覺的作法，去跑一個從`0`到`n`的迴圈，之後在迴圈中跑一個最多跑32次的`while`迴圈，使用Shifting的方式來數各個數字中有多少個`1`。

本來想說裡面的回圈最多就跑32次，應該可以把它當成時間複雜度中的常數項，因此以為這樣的時間複雜度為`O(32n)=O(n)`。但後來看到答案才發現不對，雖然裡面的迴圈最多跑32次，但這其實跟輸入的數字大小有關，因為輸入的事`int32`的變數，因此他最多才會跑`32`次，這個`32`其實是`O(logn)`。

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            int count = 0, num = i;
            while(num != 0) {
                if (num & 0x00000001) count++;
                num = num >> 1;
            }
            result.push_back(count);
        }
        return result;
    }
};
```

![圖片](https://user-images.githubusercontent.com/55487740/202842514-ac1d7fd4-47b7-436c-9ae5-eaac44bf1d89.png)
