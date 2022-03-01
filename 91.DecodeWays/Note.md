# Note 

這題給我們一個編碼過的字串，各個字元編碼的結果介於`1`跟`26`，假如有兩個連續的Digits兜起來的範圍介於`10`～`26`之間，就可以將他們當成一個文字來解碼。由於編碼的結果包含不同長度的編碼結果，因此不同的訊息有可能被編碼成相同的文字，題目希望我們去看一個編碼訊息有幾種解碼的可能性。
- 題目的編碼方式為：`A`編碼為`1`，`Z`編碼為`26`（中間的字母以此類推）。
- 假如有一個編碼結果為`"05"`，那這個訊息其實不合法，原因是沒有`0`這個編碼，因此這組訊息的解碼結果只有`0`種可能性。

## My DP Solution

在看長度為`n`的編碼訊息時，我先去看長度為`n-1`的訊息一共有多少種解碼結果，之後再用該結果得到長度為`n`時的結果，不過這個關係有點複雜。整體概念為：長度為`n-1`的訊息的解碼方式可以看成編碼訊息中各個Digits的排列，假如各種排列結果的最後一個元素為`1`或者`2`，就代表在加入一個字元後，如果倒數兩個數字組合起來的範圍介於`10`、`26`中間，該組排列方式就有辦法變成兩種不同的排列。舉例來說，有一個排列方式的結尾為`2`，這時如果加入一個新的數字`5`，就可以將這兩個數字排列成`2, 5`或者`25`。接著我們可以知道，長度為`n`的訊息的解碼可能性與`n-1`中`1`、`2`結尾的排列有關，如果這樣的排列一共有`o`個，並且`n-1`本身有`a`種可能性，那麼長度為`n`的訊息一共會有`a+o`種可能性（因為有`o`個排列方式可以變成兩種不同排列）。上述都了解以後就可以知道，我們可以使用變數`oneDigitAmount`來紀錄長度為`n-1`時，以`1`、`2`結尾的排列方式有幾種；使用變數`amount`來記錄長度為`n-1`時，一共有幾種解碼方式。之後就可以得到長度為`n`的編碼訊息一共有`amount+oneDigitAmount`種可能性。

這個方法麻煩的點在於要想到`oneDigitAmount`跟`amount`在加入新的數字時會於何變化，其規則如下：
- 如果加入的數字為`0`：不能單獨存在，一定要綁著前面的數字一起解碼，並且假如前面的數字為`1`或`2`才能構成合法編碼，假如前面的數字為其他數值則為非法編碼，因此可以直接回傳`0`。當前面的數字為`1`或`2`時，由於新加入的數字一定要跟綁前面的數字在一起，因此如果結尾為兩位數的排列方式就一定會被拿掉（沒辦法跟新加入的`0`合併）。最後可以知道`amount`會等於前一個狀態的`oneDigitAmount`，而`oneDigitAmount`會等於`0`。
- 如果新加入的數字為`1`或`2`：如果新加入的數字跟前一個數字組合的結果介於`10`跟`26`，加入新的數字後就可以產生額外的排列方式，因此他的`amount`就會等於前一個狀態的`amount`加上前一個狀態的`oneDigitAmount`，而`oneDigitAmount`會等於前一個狀態的`amount`；反之，如果跟前一個數字組合的結果為其他數值，那麼在加入新的數字之後就沒辦法產生額外的排列方式，因此`amount`跟`oneDigitAmount`就都會等於前一個狀態的`amount`。
- 如果新加入的數字大於`2`：`amount`的變化會跟前一種相同，但因為新加入的數字不再是`1`或`2`，因此`oneDigitAmount`會等於`0`。

時間複雜度為`O(n)`。

<img width="633" alt="圖片" src="https://user-images.githubusercontent.com/55487740/156187553-832e85ca-3d65-414b-b996-35cfc01480bd.png">

### Code

```cpp
int Solution::numDecodings(string s){
    int oneDigitAmount, amount, lastAmount, lastOneDigitAmount, i;
    if (s[0] == '0') return 0;
    lastOneDigitAmount = oneDigitAmount = (s[0] == '1' || s[0] == '2')? 1:0;
    lastAmount = amount = 1;
    for (i = 1; i < s.size(); i++){
        int last2Digits = stoi(s.substr(i-1, 2));
        if (s[i] == '0'){
            if (last2Digits == 10 || last2Digits == 20) oneDigitAmount = 0;
            else return 0;
            amount = lastOneDigitAmount;
        }
        else if (s[i] == '1' || s[i] == '2'){
            if (last2Digits >= 11 && last2Digits <= 26) amount += lastOneDigitAmount;
            oneDigitAmount = lastAmount;
        }
        else{
            if (last2Digits >= 11 && last2Digits <= 26) amount += lastOneDigitAmount;
            oneDigitAmount = 0;
        }
        lastOneDigitAmount = oneDigitAmount;
        lastAmount = amount;
    }
    return amount;
}
```

## 別人用Recursion加Memorization的作法

由於一個或兩個Digits都有可能組成合法編碼，因此對於一個長度為`n`的字串，他把他拆成將第一個數字、前兩個數字拿掉的情形去做遞迴，這兩個遞迴的結果就是長度為`n`的字串的可能解碼結果。要注意的是如果前兩個數字無法組成合法的編碼，那就只需要去看「將第一個數字拿掉後，長度為`n-1`的遞迴結果」。假如不使用Memorization的話，這個方法的時間複雜度為`O(n^2)`，但是使用了Memorization來避免重複遞迴之後，時間複雜度就可以降為`O(n)`。

![圖片](https://user-images.githubusercontent.com/55487740/156191368-104d4142-7874-4105-a350-952ba9f039d9.png)

### 程式碼

Time complexity: `O(n)`
Space complexity: `O(n)`

```cpp
// Author: Huahua
// Runtime: 3 ms
class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        return ways(s, 0, s.length() - 1);
    }
 
private:    
    int ways(const string& s, int l, int r) {        
        if (m_ways.count(l)) return m_ways[l];
        if (s[l] == '0') return 0;
        if (l >= r) return 1; // Single digit or empty.
        
        int w = ways(s, l + 1, r);
        const int prefix = (s[l] - '0') * 10 + (s[l + 1] - '0');
        
        if (prefix <= 26)
             w += ways(s, l + 2, r);
        
        m_ways[l] = w;
        return w;
    }
    
    // Use l as key.
    unordered_map<int, int> m_ways;
};
```
