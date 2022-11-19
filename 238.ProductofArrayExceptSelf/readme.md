# Note

這題給我們一個輸入數列，要我們找出數列中除了自己以外的乘積。詳細的說，他要回傳一個長度為`n`的數列，第`i`個元素為數列中除了第`i`個元素以外的乘積。

## My Solution

我的作法滿直覺的，想了一下，如果要找出除了第`i`個元素以外的乘積，那其實就是將`nums[0] * nums[1] * ... * nums[i-1]`乘以`nums[i+1] * nums[i+2] * ... * nums[-1]`。基於這樣的觀察，我使用兩個數列分別存放從左連乘到最後的乘積，以及從最右連乘到最左的乘積。之後再跑一個迴圈，讓`result[i] = fromLeftMulti[i-1] * fromRightMulti[i+1]`。

這樣算起來時間複雜度跟空間複雜度都為`O(n)`。

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fromLeftMulti(nums.size(), 0), fromRightMulti(nums.size(), 0), result(nums.size(), 0);
        fromLeftMulti[0] = nums[0];
        fromRightMulti[fromRightMulti.size()-1] = nums[nums.size()-1];
        for (int i = 1; i < nums.size(); i++) {
            fromLeftMulti[i] = fromLeftMulti[i-1] * nums[i];
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            fromRightMulti[i] = fromRightMulti[i+1] * nums[i];
        }
        result[0] = fromRightMulti[1];
        result[result.size()-1] = fromLeftMulti[result.size()-2];
        for (int i = 1; i < nums.size()-1; i++) {
            result[i] = fromLeftMulti[i-1] * fromRightMulti[i+1];
        }
        return result;
    }
};
```

![圖片](https://user-images.githubusercontent.com/55487740/202842023-6b821514-e186-47f6-bf73-95b0be3f3d57.png)

## 把空間複雜度降到`O(1)`

其實可以將`result`紀錄為從左跑到右的連乘結果，之後再從右到左，使用一個變數`rightMul`紀錄右到左的結果。由於右到左的時候已經有左到右的資訊、右到左的資訊，因此可得解。

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        result[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result[i] = result[i-1] * nums[i];
        }
        int rightMul = 1;
        for (int i = nums.size()-1; i > 0; i--) {
            result[i] = result[i-1] * rightMul;
            rightMul *= nums[i];
        }
        result[0] = rightMul;
        return result;
    }
};
```
