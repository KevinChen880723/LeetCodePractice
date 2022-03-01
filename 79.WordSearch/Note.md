# Note

## Baseline Solution

這題給定我們一個大小為`m*n`的二維陣列`board`，並要我們去看文字板中是否存在`word`，所謂的存在是指：以四方位相鄰的方式檢查兩個字元是否連續，如果`word`中的所有字元皆連續就代表`word`存在，另外題目還要求同一個位置的字元只能使用一次。我這題的作法為：先在地圖中找出所有等於`word[0]`的位置，之後從那些位置開始以DFS的方式去做四方位搜尋，為了避免使用到相同位置的字元，我使用Call by Value來傳一個跟`board`一樣大的布林物件`srcPath`來記錄來的路，他在Top Function裡面全部都是`false`，傳到`searchFromStartPoint`函數後，在每走一步路之後就將該位置標為`true`，假如之後發現新的路已經走過了就直接略過。不過這個做法在LeetCode上運算超時。

<img width="811" alt="圖片" src="https://user-images.githubusercontent.com/55487740/156103021-1340ec0d-54f4-4873-a828-dfbaffe0d8ad.png">

## Better Solution

我後來去看網路上人家的解法結果發現跟我差不多，只差在他沒有使用`srcPath`，而是直接在每次走完一步之後先將`board`在該位置的值清為`word`中不可能出現的值，之後才再往下遞迴，這樣就可以避免在往下遞迴的過程中找到相同位置的字元。要注意的是在遞迴結束之後要記得將該位置的字元復原，否則之後從其他起點出發時會少一些可以走的路。他使用這種方法就可以通過LeetCode的測試，並且可以超過LeetCode上82%的人。後來才知道原因是我原本用Call by Value的方式來傳二維陣列的話，因為他需要一個一個將資料複製到新的記憶體位置，呼叫一次遞迴程式就至少需要`O(mn)`的時間，造成整體運行時間被拖慢。

<img width="527" alt="圖片" src="https://user-images.githubusercontent.com/55487740/156102907-c8eac423-db8e-4603-a033-0dc5018063d5.png">
