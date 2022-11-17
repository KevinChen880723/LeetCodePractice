# Note

這題希望我們在不使用加減法運算子的條件下，實現加減法。看到題目後，想一想覺得乘法除法餘數什麼的都沒辦法解決，大概也只能用二進制的角度來思考惹。

## My Solution

一開始的想法是我需要先把輸入的數字轉成`vector<bool>`的變數，接著做完加法再把他轉回`int`輸出。一開始做第一步驟的時候左右碰壁一下想到可以用Shifting的方式，跑一個迴圈將整數以二補數的方式存到`vector<bool>`的變數中，由於記憶體中的變數本來就會存成二進制，因此這個過程非常簡單。不過後來想到，其實要這樣做不如直接對原來的數字做Bit manupulation，畢竟他本來就已經用二補數的方式存放惹。
我的作法變成是使用一個一開始初始化為`1`的`bit_parser`來跟輸入的數值做Bit-wise的AND運算，這樣就可以取得輸入變數的最小位元。然後因為我跑了一個回圈讓`bit_parser`在每次迭代的時候都左移，因此我們可以做到依序從最小位元抓到最大位元。有辦法取得各個位元後，就可以使用這個搭配`cin`跟卡諾圖來得到最後的結果。

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        bool cin = 0;
        int bit_parser = 1, final_result = 0;
        for (int i = 31; i >= 0; i--) {
            bool b_bit = b & bit_parser, a_bit = a & bit_parser;
            bool bit_result = a_bit ^ b_bit ^ cin;
            final_result = (bit_result == 1)? final_result | bit_parser: final_result;
            cin = (cin & b_bit) | (cin & a_bit) | (a_bit & b_bit);
            bit_parser = (unsigned int)bit_parser << 1;
        }
        return final_result;
    }
};
```

![圖片](https://user-images.githubusercontent.com/55487740/202367924-51f12f05-9e8e-4175-940a-261db7131993.png)

## LeetCode上別人的Solution

我覺的他的方法比較聰明，由於兩位元的加法不管進位就是XOR運算，而兩位元判斷進位則是用OR運算，因此他直接使用XOR運算得到還沒加上`cin`的結果，另外再使用`temp`當作OR運算的結果，再把`temp`指定給`b`，這時候`b`就代表`cin`了。而我們知道如果`cin`還存在，就代表加法還沒完成，因此我們可以將`while()`的條件設定為`b != 0`。

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int temp = (unsigned int)(a&b)<<1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
};
```
