# Note

這題給我們一個數列，數列的Index代表的是買賣股票的日期，而對應的數字代表當天某張股票的價格。題目問我們在哪一天買、哪一天賣可以最賺錢，也就是說怎麼樣的情況右邊數減左邊數字會得到最大的結果。

## Baseline Solution

- 我的作法是使用`l`、`r`兩個指標來分別指向左右兩個數字，每一次只選擇將一個指標往裡面移動一步。我選擇移動哪個指標的方式為：去選擇當下可以產生最大結果的移動方式，除了使用`l`、`r`變數來紀錄當前位置以外，我也使用`l_smallest`、`r_largest`來紀錄目前為止對應到最小及最大數字的左右指標位置，每次選擇要移動的時候就去看`(r-1) - l_smallest`會不會比`r_largest - (l+1)`還大，如果成立的話就將`r`往中間移動，反之則將`l`往中間移動。
- 時間複雜度：`O(n)`。

```cpp
int maxProfit(vector<int>& prices) {
    int l = 0, r = prices.size()-1;
    int l_smallest = l, r_largest = r;
    int bestValue = prices[r] - prices[l];
    while (r > l) {
        if (prices[r_largest]-prices[l+1] > prices[r-1]-prices[l_smallest]) l++;
        else r--;
        l_smallest = (prices[l] < prices[l_smallest])? l: l_smallest;
        r_largest = (prices[r] > prices[r_largest])? r: r_largest;
        bestValue = max(bestValue, prices[r_largest] - prices[l_smallest]);
    }
    return bestValue;
}
```

![](https://i.imgur.com/XIU2NTl.png)

## Dynamic Programming

昱豪的作法：不使用兩個變數分別記錄大的、小的數字，而是只使用一個變數`cur`來記錄兩個數字相減的結果。過程中會從頭看到尾，如果原本右邊的數字在被換成新的數字後可以讓結果變大，就更新`cur`；由於他使用的是累加的方式，這種情況下假如`cur`變得比零還小，就代表左邊的數字比右邊的數字還大了，如果我們還繼續固定左邊的話一定會讓結果變小。為了避免這個問題，假如`cur`小於零，就將`cur`歸零，也就是下一次更新再去找一組完全新的數字。

> 他這個做法雖然也是`O(n)`，但因為每一次回圈要執行的程式比我少，因此運算起來會比我快一點點。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, cur = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(cur + prices[i] - prices[i-1] > 0)
                cur = cur + prices[i] - prices[i-1];
            else
                cur = 0;
            if(cur > res)
                res = cur;
        }
        return res;
    }
};
```

<img width="693" alt="圖片" src="https://user-images.githubusercontent.com/55487740/156964597-10e59661-069a-4022-94d5-a072fd9cb658.png">

## Skyler Solution

我覺得Skyler的做法最直覺，他就是使用一個`minBuy`來記錄當前最小的買入金額，並使用一個`maxProfit`紀錄當前最大收益。演算法中使用一個迴圈來從頭到尾遍歷每天的金額，若當前減去`minBuy`大於`maxProfit`，則更新`maxProfit`；而如果當前數值比`minBuy`還小的話，就將`minBuy`更新為此數值，此數字可以用於後續的比較。
