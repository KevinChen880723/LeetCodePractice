# Note

## Bruteforce Solution

這題給定我們一堆字串資料，希望我們去找出Anagram的組合，也就是把由相同字元組成的資料分到同一個集合。我暴力解的作法為：依序遍歷所有輸入字串，接著去看各個字串應該被分到哪一個集合，如果當前還不存在他對應的集合，就新增一個集合；反之，如果他對應的集合已經存在，就將當前字串加入該集合中。所以整體過程一共會需要以下功能：
1. 給定兩個字串，看他們是否互為Anagram：我使用Hash map實現這個功能，在我的方法裡面需要先依序看字串中的各個字元，之後用Hash map去搜尋字元是否在另一個字串中，因此如果最長的字串的長度為`k`，那麼此功能的時間複雜度就會是`O(k)`。
2. 將當前搜索到的字串跟所有集合的字串比較：由於所有集合的字串都相同，因此跟各個集合做比較時，只需要跟第一個字串比較。當我看到第`n`個字串，當前最多會存在`n-1`個集合；當我看到第`1`個字串，當前最多存在`0`個集合，因此這個功能的時間複雜度為`(((n-1)+0)*(n-1))/2`，也就是`O(n^2)`。

基於以上的分析可以知道整體時間複雜度應該會是`O(kn^2)`，這樣的複雜度在LeetCode中會超時。

## Hash Table Solution

這是LeetCode提供的解法，我前面雖然也有使用到Hash Table，但我以為Hash Table只能把字元當作Key來搜尋，所以沒有真正的善用hash Table的功能。事實上Hash Table可以使用字串物件作為Key，一開始可能會想說這樣會不會發生Collision，還要解決這個問題很麻煩什麼的，但其實C++提供的`unordered_map`就已經幫我們解決了這個問題了。在LeetCode提供的解法中就將字串作為Hash Table的Key，由於如果兩個字串互為Anagram，就代表字串當中各個字母出現的次數相同，因此可以先去紀錄各個字母出現的次數，之後再將結果轉換為字串來搜尋。由於Hash Table的搜尋只會耗費`O(1)`的時間，因此跑起來非常的快。不過要注意的是：作為Key的字串中的各個數字之間應該要有一些符號作為區隔，要不然可能`12`個a, `3`個b的結果也可以被解讀為`1`個a, `23`個b。

<img width="684" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155062510-96b9c346-9bcc-493d-a688-886ca1df8ffd.png">