# Note for TwoSum

## Baseline Function

### English Version

Firstly, in the program, I sort the series, then check every number in `nums` sequentially. When checking every value, I search the corresponding paired number from the end of the series. When searching the corresponding number, I set the different start points determined in the last iteration because the number I checked in the new iteration is bigger than the previous iteration.

### Mandarin Version

為了找出哪兩個數字相加可以組成目標數字，在這個程式中我先將輸入的數列`nums`排序，接著從最小的數字開始尋找該數字對應的另一個數字。由於我是從最小的數字開始看，因此我在搜尋他對應的數字時，我從最後面開始搜尋，假如搜尋到目標數字就直接回傳結果不再繼續運行。由於我每次看的新數字都會比舊數字大，而兩個數字在相加時如果有一個數字相加的結果一定會變大，因此每看一個新的數字我就可以把一些過大的數值過濾掉，在程式中為了實現這個功能，我設定了`upperBound`變數，如果編號`i`、編號`j`的數字相加的結果大於`target`則將`upperBound`更新為`j`，之後搜尋下一個數字對應的數字時就可以從`upperBound`開始搜尋，而不必從`len-1`開始。

另外，副程式回傳的結果應該要是找到的數字在原本數列中的位置，但是我在一開始已經將數列做過排序了，這會導致最後回傳錯誤編號。為了解決這個問題，我建立新的變數型態`num`，立面除了數列的數值以外，還記錄著原本數字出現的位置，如此一來，即使將數列重新排序過了，也能得知各筆資料在原先數列中出現的位置。
