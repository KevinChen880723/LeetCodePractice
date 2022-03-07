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
