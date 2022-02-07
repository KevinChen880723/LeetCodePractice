# Note

## Baseline Function

### Mandarin Version

這個題目是希望我們去找出在字母不重複的情況下，一個字串中最長子字串的長度。例如：
- 輸入字串為`dvdf`時，最長子字串為`vdf`，因此函數應該回傳3。
- 輸入字串為`abcabcbb`時，最長子字串為`abc`，因此函數應該回傳3。
- 輸入字串為`pwwkew`時，最長子字串為`wke`，因此函數應該回傳3。

我想到的方法為：從字串的開頭開始Traverse，過程中使用字串物件`currentLongestString`來記錄當前最長的子字串，使用字串物件`newString`來紀錄加入新字元後可以組成的最大子字串。過程中如果`newString`的長度比`currentLongestString`長的話，就將`currentLongestString`取代為`newString`。其中我們還會不斷地檢查在加入新字元以後`newString`會不會出現重複的字元，如果重複的話就將`newString`更新為第一個重複的字的後一個位置到結尾的子字串再加入新字元。（這樣做的原因是過程中我們在更新`newString`的過程中，如果`newString`比`currentLongestString`長了，就會將`currentLongestString`取代為`newString`，因此不需要擔心本來的`newString`明明比較長卻被取代的問題）
