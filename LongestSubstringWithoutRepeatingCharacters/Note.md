# Note

## Baseline Function

### Mandarin Version

這個題目是希望我們去找出在字母不重複的情況下，一個字串中最長子字串的長度。例如：
- 輸入字串為`dvdf`時，最長子字串為`vdf`，因此函數應該回傳3。
- 輸入字串為`abcabcbb`時，最長子字串為`abc`，因此函數應該回傳3。
- 輸入字串為`pwwkew`時，最長子字串為`wke`，因此函數應該回傳3。

我想到的方法為：從字串的開頭開始Traverse，過程中使用字串物件`currentLongestString`來記錄當前最長的子字串，使用字串物件`newString`來紀錄加入新字元後可以組成的最大子字串。過程中如果`newString`的長度比`currentLongestString`長的話，就將`currentLongestString`取代為`newString`。其中我們還會不斷地檢查在加入新字元以後`newString`會不會出現重複的字元，如果重複的話就將`newString`更新為第一個重複的字的後一個位置到結尾的子字串再加入新字元。（這樣做的原因是過程中我們在更新`newString`的過程中，如果`newString`比`currentLongestString`長了，就會將`currentLongestString`取代為`newString`，因此不需要擔心本來的`newString`明明比較長卻被取代的問題）

## Using Sliding Window

這個方法跟我的Baseline Function差不多，只是我是使用兩個字串來紀錄當前最長字串、當前檢視字串，但這個方法只使用了一個物件來紀錄當前檢視字串，另外只使用一個變數來紀錄當前的「最大長度」。除此之外，他這邊不使用字串來紀錄當前檢視字串，而是使用Hash map的方式，透過這樣的方式可以在O(1)的時間檢查字元是否重複（使用我目前的方法需要耗費O(n)的時間來檢查）。由於此方法只需要O(1)的時間就可以完成重複字元的檢測，因此整體的時間複雜度只有O(n)。

> 下圖為此方法的部分程式碼，可以發現他這邊的Hash map使用不同於[twoSum](https://github.com/KevinChen880723/LeetCodePractice/blob/master/TwoSum/twosum.cpp#L45)中使用的方式，他使用的是一個長度為128的`vector<int>`。Vector的長度之所以是128是因為：字元為8位元，因此只需要大小為128的Vector就可以讓一個字元對應到Hash map中的一個bin。

![](https://i.imgur.com/fiXzXNS.png)
