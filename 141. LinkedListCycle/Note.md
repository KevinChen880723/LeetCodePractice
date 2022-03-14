# Note

## Hashset Solution

使用一個Hashset來記錄所有過程中遇到的節點的記憶體位址，假如有Cycle的話一定會再走到這些重複的位址，因此每次往前走一步並檢查當前記憶體位址是否存在於Hashset中，如果有的話就直接回傳`true`；反之，如果走到底的話就回傳`false`。這個方法的時間複雜度跟空間複雜度都為`O(n)`。

<img width="766" alt="圖片" src="https://user-images.githubusercontent.com/55487740/158103604-c1a74c4d-70e0-4b14-a7f4-566bbe95239d.png">

## Two Pointer Solution

為了做到`O(1)`的空間複雜度，可以使用快慢指標的方式：一開始先將兩個指標都指向`head`，之後快指標一次移動兩步，慢指標一次移動一步，假如存在Cycle則快指標一定會追到慢指標，因此判斷兩個指標是否重疊，如果重疊就直接回傳`true`。為什麼快指標跟慢指標重疊就代表存在Cycle呢？原因是如果存在Cycle，快指標跑得比較快，因此經過一段時間一定會追上慢指標。不過最差的情況要多少時間才能追到呢？最差的情況就是慢指標進入Cycle時，快指標剛好在慢指標的前一個位置，這種情況下假如Cycle的長度是`q`，那麼快指標就要追`q-1`步才能追到慢指標。由於快指標的速度為`2`，慢指標的速度為`1`，因此式子可以列成：`2t >= t+q-1`，移項一下就可以得到當`t`超過`q-1`時，快指標可以追上慢指標。由於`q`小於`n`，因此最多也只需要花`O(n)`的時間來得到答案。

<img src="https://i.imgur.com/LuCOetF.png" width=70% style="margin-left: auto;margin-right: auto;">

<img width="725" alt="圖片" src="https://user-images.githubusercontent.com/55487740/158103457-96cc414c-0802-4013-ba87-9d6a90955bab.png">
