# Note

## My Solution

一開始我覺得過程中只需要判斷當前看到的數值是否為零，如果是零的話就將當前數值更新為`1`，並且當前回合不要更新`maxProduct`；如果不是零的話就持續相乘，過程中如果當前乘積大於`maxProduct`就更新`maxProduct`數值。不過這個做法有個問題，就是：假如中間出現了一個負數，之後就都沒有負數了，這種情況下如果那個負數之後出現了最大乘積就不會被發現了。

後來再想一下覺得經過一個負數之後，如果後面還有其他負數的話，原本相乘的結果就還有機會成為最大值；但如果後面沒有其他負數的話，最大值有可能可以從該負數的下一個數字開始連乘得到。基於這個原因，我覺得要使用兩個變數`negProduct`、`posProduct`來記錄當前最大正負值，假如：
1. 新遇到的數字是正數：由於不會影響正負符號，因此可以直接相乘，不過要檢查一下當前`posProduct`是否大於零，假如他變成負數就代表上一輪中他乘以負數了，因此應該將它更新為當前遇到的這個正數。
2. 新遇到的數字是負數：由於我們在遇到正數的時候會去檢查`posProduct`是否大於零，如果他小於零就會做出調整，而且即使他小於零也不會影響當前最大乘積的結果，因此可以直接將`posProduct`乘以新遇到的負數沒關係。至於`negProduct`的話，他的功能只是用來存放變成負數的`posProduct`，假如`posProduct`本來就是負數，則改成從當前這個新的負值開始做連乘。

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], negProduct = 1, posProduct = 1, i;
        for (i = 0 ; i < nums.size(); i++) {
            if (nums[i] > 0) {
                negProduct *= nums[i];
                posProduct = (posProduct < 0)? nums[i]: posProduct*nums[i];
                maxProduct = max(maxProduct, max(negProduct, posProduct));
            }
            else if (nums[i] < 0) {
                int prev_neg = negProduct;
                negProduct = (posProduct < 0)? nums[i]: posProduct*nums[i];
                posProduct = prev_neg * nums[i];
                maxProduct = max(maxProduct, max(negProduct, posProduct));
            }
            else {
                negProduct = posProduct = 1;
                maxProduct = max(maxProduct, 0);
            }
        }
        return maxProduct;
    }
};
```

![](https://i.imgur.com/PR4hrop.png)

## LeetCode Solution

網路上這個人的方法聰明多了，沒有一堆奇怪的條件。他的概念可以從簡單到題目要求的情況依序講解：
1. 假如數列中只存在正數：最大的乘積就會是所有數字相乘的結果。
2. 假如數列中除了正數以外還存在`0`：在遇到`0`的時候連乘的結果就會被歸零，假如不做特殊處理的話，就會導致怎麼乘都是零。為了解決這個問題，他使用`maxProd = max(maxProd*n, n);`的方式來處理，在遇到`0`以後`maxProd`就會被歸零，因此使用這樣的方式可以將結果更新為新的數字，也就是從新的地方開始連乘。
3. 假如數列中還存在負數：連乘到一半如果遇到負數就會導致本來很大的乘積瞬間變超級小，但假如之後又遇到另一個負數就可以讓乘積又變回最大。因此他的方法中除了使用`maxProd`以外，還另外使用`minProd`來記錄當前最小的乘積，假如遇到負數的話就將`minProd`跟`maxProd`交換，交換以後`maxProd`就會先變成本來最小的乘積（也就是中間因為乘以一個負號而變成的負數），因此再乘以新的這個負數之後他又可以再變回最大值。

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Return early if input is empty
        if (nums.empty()) return 0;

        int best = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;

        for (int n: nums) {
            if (n < 0) {
                // Swap max and min
                swap(maxProd, minProd);
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            // Update the best
            best = max(best, maxProd);
        }

        return best;
    }
};
```

<img src="https://user-images.githubusercontent.com/55487740/158535330-093eeb49-cf7a-4c4a-8fa5-5fa1fd4e9b39.png" style="width: 100%">
