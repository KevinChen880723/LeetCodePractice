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

## My Solution (Dynamic Programming)

這次的解法是去找規律。就像以前在畫真值表的時候，如果是`4`位元，那我都會直接在最高位元那行先寫八個`0`再八個`1`，第二高位原則是會寫四個`0`四個`1`再四個`0`四個`1`，以此類推，這其實就是他的規律。原因是當數字為`2^n-1`時，全部都會是`1`，但是到了`2^n`時，就會只剩下一個`1`了，他的數值其實是`0 + 2^n`。

基於這樣的觀察，我這次使用DP來解這題，有一個變數`exp_idx`記錄著當前已經看到超過`2^exp_idx`，因此`result[i]`的數值應該為`result[i-pow(2, exp_idx)]`加一。而為了讓`i`超過`2^exp_idx`時，可以讓`2^exp_idx`對應到`i`，因此當`i`等於`pow(2, exp_idx+1)`時，`exp_idx`加一。

這樣做的時間複雜度才會是`O(n)`。

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        int exp_idx = 0;
        for (int i = 1; i <= n; i++) {
            if (i == pow(2, exp_idx+1)) {
                exp_idx++;
            }
            result[i] = result[i-pow(2, exp_idx)] + 1;

        }
        return result;
    }
};
```
<img width="1379" alt="圖片" src="https://user-images.githubusercontent.com/55487740/202843505-59ecbb48-802e-405a-964b-e5e6ed42e58c.png">
