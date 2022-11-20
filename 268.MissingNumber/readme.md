# Note

這題給我們一個長度為`n`的數列，他的範圍其實會對應到`[0, n]`，但裡面缺了某個數字才會讓長度只剩下`n`。這題就是要我們找出他缺的是哪個數字。

## My Solution

由於數列中的數字應該要是`0`到`n`，因此我可以先用求等差級數和的方式找出完整`[0, n]`的總和，之後一個一個減去數列中的數字，最後剩下多少就是缺少哪個數字。

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numSum = (1 + nums.size()) * nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            numSum -= nums[i];
        }
        return numSum;
    }
};
```

<img width="1389" alt="圖片" src="https://user-images.githubusercontent.com/55487740/202878159-cc69b364-3792-4bff-92d4-b09f432c6546.png">

## XOR Solution

另外一種解法使用的是XOR運算的特性：
- 0 XOR a = a
- a XOR a = 0：任何數字跟`0`做XOR，結果不變。
- 0 XOR a XOR a = 0
- a XOR 0 XOR a = 0: 不管怎麼調換順序，只要有做到兩個相同數字的XOR，結果就會變成`0`。

使用以上特性，一開始將`result`設定為`0`，之後跟`0`到`nums.size()`做XOR，再跟`nums`中的所有數字做XOR，最後結果就會是缺少的那個數字。原因是我們已經跟`0`到`nums.size()`的所有數字做過XOR了，這時如果`nums`中有出現相同的數字，該數字的運算結果就會變成`0`。而他變成`0`後我們可以使用`0^a=a`的特性，假如有個數字是`[0, n]`有出現，但是在`nums`中沒有出現，那最後結果就會剩下那個數字。

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ i ^ nums[i];
        }
        result = result ^ nums.size();
        return result;
    }
};
```
