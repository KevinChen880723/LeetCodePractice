# Note

這個題目希望我們在一個經過旋轉的數列中找出數列的最小值。題目本身跟第33題很像，不過那題是給定我們一個數字，我們有一個明確目標；但這題是要找出最小值，我們一開始不會知道目標數值是多少。

## My Solution

要解這題要先知道最小值會出現在什麼地方：
- 如果數列有被旋轉過，那麼最小值一定會出現在`breakpoint`的右邊。
- 如果數列沒有被旋轉過，那麼最小值一定會出現在最左邊。

我採用類似Binary Search的作法來實現這題，但由於他給定的數列有經過旋轉，需要使用修改版的Binary Search。透過前面的筆記可以知道最小值不是出現在旋轉數列中`breakpoint`的右邊，就是出現在非旋轉數列的最左邊。因此一開始可以先去判斷數列是否為旋轉數列，假如`nums[r]`比`nums[middle]`小，就可以知道`breakpoint`出現在右邊；如果`nums[l]`比`nums[middle]`大，就可以知道`breakpoint`出現在左半邊；假如以上兩個條件都不成立的話就可以知道當前數列沒有被旋轉過，因此最小值可能出現在最左邊。

> 我這邊採用的方法是拿中間的跟最左邊、最右邊比較，透過這樣的方式可以知道`breakpoint`有可能在左右兩邊，但其實也有可能`middle`剛好就對應到`breakpoint`，因此過程中也要不斷看`middle`是不是最小值。

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, currentSmallest = INT_MAX;
        while (r > l) {
            int middle = (l + r) / 2;
            currentSmallest = min(currentSmallest, nums[middle]);
            // The breakpoint is possibly in the right part.
            if (nums[middle] > nums[r]) l = middle + 1;
            // The breakpoint is possibly in the left part.
            else if (nums[middle] < nums[l]) r = middle - 1;
            // No breakpoint. The minimum value is possibly nums[l].
            else break;
        }
        currentSmallest = min(currentSmallest, nums[l]);
        return currentSmallest;
    }
};
```

![](https://i.imgur.com/oXGOkfH.png)
