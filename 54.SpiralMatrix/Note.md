# Note

## Solution

這題輸入一個二維陣列，希望以螺旋的順序輸出陣列中的資料。這題使用遞迴可以輕鬆的完成，在每一層遞迴中只需要負責印出最外面那圈的資料，最後如果中間還有沒印出來的資料，再將中間比較小的矩陣傳入相同的函數中來印。其中我印外圈資料的方式為：
1. 先將第一排資料全部印出來。
2. 接著如果矩陣的列數有超過`3`，就將最右邊的資料印出來。
3. 之後如果矩陣的列數有超過`2`就把最下面那列印出來。
4. 最後如果矩陣的列數有超過`3`，而且矩陣的行數有超過`3`，就將最左邊那行資料印出來。

<img width="633" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155129155-0f72cfa3-5559-49b4-84d8-fb78cca98b21.png">