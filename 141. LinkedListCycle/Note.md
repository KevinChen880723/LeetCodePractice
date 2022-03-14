# Note

## Hashset Solution

使用一個Hashset來記錄所有過程中遇到的節點的記憶體位址，假如有Cycle的話一定會再走到這些重複的位址，因此每次往前走一步並檢查當前記憶體位址是否存在於Hashset中，如果有的話就直接回傳`true`；反之，如果走到底的話就回傳`false`。

<img width="766" alt="圖片" src="https://user-images.githubusercontent.com/55487740/158103604-c1a74c4d-70e0-4b14-a7f4-566bbe95239d.png">

## Two Pointer Solution

<img width="725" alt="圖片" src="https://user-images.githubusercontent.com/55487740/158103457-96cc414c-0802-4013-ba87-9d6a90955bab.png">
