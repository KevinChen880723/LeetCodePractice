# Note

## Baseline Solution

這題給定我們兩個字串`S`、`T`，他要我們在`S`字串中找出包含`T`的最小子字串（如果`T`中包含重複的字元，`S`也要包含至少一樣多的該字元）。這是我自己的作法，時間複雜度為`O(n)`，作法為：
1. 使用Hash map來對應字串`T`中所有字元出現的次數`num`、存放各個字元出現位置的`posList`。除此之外，再另外使用一個變數`currentDesiredAmount`來紀錄當前還需要幾個字串`T`中的字元。
2. 如果在尋找過程中找到一個字元，就要將對應的字元數量減一，並且也要將新的位置加入紀錄位置的`posList`中。這邊要注意的是：對於各個字元來說，當他對應的數字`num`為零的時候就代表我們已經成功找到目標數量的該字元，因此如果又遇到一樣的字元，就將最一開始遇到的移除，之後才加入新的位置；不過如果`num`還沒歸零的話，則可以直接加入。除了前面提到的更新`num`、`posList`以外，還要更新`currentDesiredAmount`。由於`num`在等於零的時候代表我們不再缺這個字元，在大於零的時候代表我們缺幾個該字元，因此我們只有在`num`不為零時才可以將`currentDesiredAmount`減一，
3. 如果`currentDesiredAmount`為零就代表我們找到一個符合規範的子字串，這時候就可以去看他的長度，如果他的長度比原本的還小的話，就將`currentBestSubString`更新為新的子字串。

<img width="715" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155848255-0316e064-fe97-4edf-9df6-42afbc6cd86c.png">
