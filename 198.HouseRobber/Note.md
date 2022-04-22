# Note

題目的情境是一個小偷要偷錢，但如果連續偷兩戶的錢就會觸發警報，他問我們如果是小偷，要怎麼在不觸發警報器的情況下偷到最多錢，其中題目給我們的數列代表對應房子裡面錢的數量。

## My Solution

由於我們希望在不能連續偷兩間房子的情況下偷到最多錢，因此我使用兩個變數`max_with_last`、`max_without_last`來記錄「有偷當前最後一間可以偷到的最多錢」、「沒有偷當前最後一間可以偷到最多的錢」。一開始先將這兩個變數初始化為`0`，之後每到一戶新的房子，就去把`max_without_last`加一。不過這個結果不一定會是最大的，因為有可能前一戶我偷到很多錢，這樣的情況下即使我多偷了一戶也不一定會比較多。為了能在這樣的情況下確保兩個變數都記錄著不同條件下的最大值，因此還需要檢查`max_with_last`有沒有比他大，如果有的話就把`max_without_last`更新為`max_with_last`。另外，我們每到一間新的房子時，應該要把兩個變數交換，因為前一次的最後一間房子在當前已經不會是最後一間了。整個過程就是不斷地重複這個步驟，就可以找出答案了！

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int max_with_last = 0;
        int max_without_last = 0;
        for (int i: nums) {
            swap(max_with_last, max_without_last);
            max_with_last = max(max_with_last+i, max_without_last); 
        }
        return max(max_without_last, max_with_last);
    }
};
```

<img width="774" alt="圖片" src="https://user-images.githubusercontent.com/55487740/164679008-1c5c01de-8334-4c49-bc7d-2db384737778.png">
