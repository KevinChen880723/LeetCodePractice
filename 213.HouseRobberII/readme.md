# Note

這題跟House Robber那題一樣，規定不能搶劫兩間連續的房子，不過差別在於這題的房子會排成一圈，因此不能同時搶第一跟最後一間。

## My Solution

一開始想好久一直想不到怎麼解，看了hint才想到，他題目是說第一間跟最後一間不能同時選到，假如選了第一間就不能選最後一間，反之亦然。因此其實我們可以直接套用House Robber的解法在兩群房子中，一群不考慮第一棟，另一群不考慮最後一棟，最後再取他們之間最大的結果就好。
其實一開始看到hint的時候會想說，難道第一間房子跟最後一間房子一定會被考慮進去嗎？其實不一定，也有可能不選那兩棟房子才是最好的偷法，而這我們可以直接套用House Robber的解法來處理。

下面的程式是這次想到的，之前解House Robber的方法其實比較有效率，不過還是大概講一下。首先我開兩個`nums.size()-1 * 2`的陣列，一個陣列會對應到小偷在偷每一棟房子時，偷與不偷這棟房子的「當前可以偷到的最多金額」。也就是如果我要偷第`i`棟房子，那麼他的金額就會是「不偷第`i-1`棟房子的最大金額」加上「第`i`棟房子的金額」；如果不偷第`i`棟房子，那麼他的金額就會是「偷第`i-1`棟房子的最大金額」。由於有兩群房子，因此只要將同樣的方法做兩遍就好。但我想說我不要重複跑兩個回圈，因此直接從頭跑道尾，然後設定當`i >= 1`的時候才開始處理第二群的陣列，當`i < nums.size()-1`時才處理第一群的陣列，然後將本來的陣列改成一個大小為`nums.size()-1 * 4`的陣列。
而我在House Robber的作法是用兩個變數紀錄「搶上一間房子的最大金額」、「不搶上一間房子的最大金額」，這樣就不需要花一堆空間紀錄一堆沒用的過時資訊。

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 3) return *max_element(nums.begin(), nums.end());

        vector<vector<int>> dpMap(nums.size()-1, vector(4, 0));
        dpMap[0][0] = nums[0];
        dpMap[0][2] = nums[1];

        for (int i = 1; i < nums.size(); i++) {
            if (i < nums.size()-1) {
                dpMap[i][0] = dpMap[i-1][1] + nums[i];
                dpMap[i][1] = max(dpMap[i-1][0], dpMap[i-1][1]);
            }           
            if (i > 1) {
                dpMap[i-1][2] = dpMap[i-2][3] + nums[i];
                dpMap[i-1][3] = max(dpMap[i-2][2], dpMap[i-2][3]);
            }
        }
        return *max_element(dpMap[dpMap.size()-1].begin(), dpMap[dpMap.size()-1].end());
    }
};
```
