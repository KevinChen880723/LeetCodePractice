# Note

## Solution

題目給我們一個已經按照左邊界排序的範圍數列，希望我們插入新的範圍，並且在加入新的範圍之後也不要出現重疊、順序亂掉的問題。本來我想說先用Binary Search來找出他應該插在哪裡，之後再往左往右將重疊的部分合併。不過問題是最後還是需要便利所有的資料來將資料放到`result`裡面，因此不如一開始就直接從頭跑到尾，還不用花時間跑二元搜尋法。我從頭跑道尾的作法為：如果當前的範圍跟我要加入的範圍沒有重疊的話，就將該筆資料加入`result`中；如果有重疊的話就不將資料加入，並且將該範圍跟新的範圍合併，然後過程中如果新的範圍找到合適的位置就把他放進去。

![](https://i.imgur.com/Q4zBsVi.png)