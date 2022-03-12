# Note

## Baseline Solution

這個解法會對應到LeetCode中的暴力解，作法為：一開始先使用`unordered_map`來記錄所有`wordDict`中的變數，這樣我們就可以讓我們在`O(1)`的時間內找到`wordDict`中是否存在我們要找的字串。另外，我們還使用另外一個函數來作為執行遞迴功能，該函數中會從頭開始一個一個將字元加入子字串中，之後去檢查該子字串是否出現在`wordDict`中，如果有的話就遞迴呼叫相同函數來檢查剩下的子字串是否歐虧；反之，如果沒有的話，就再繼續檢查；若已經將所有字元加入子字串中還找不到，就代表這個子字串不歐虧，因此回傳`false`。

使用這個方法在LeetCode中會跑不過，運算時間過長。

## Recursion with memoization

原本的作法運作起來非常慢的一個原因是他會重複檢查相同的子字串，其中每一次檢查都需要花很多時間。為了改善這個問題，其實可以使用之前用過的**Recursion with memoization**方法，將已經檢查過的資料以一個變數來記憶，這題因為丟入遞迴函數的是字串變數，回傳的是布林變數，因此記憶體變數會採用以字串作為key、以布林作為value的`unordered_map`。

<img width="725" alt="圖片" src="https://user-images.githubusercontent.com/55487740/158025377-5f3de77e-c8de-4795-b2c9-14f64c938c4e.png">
