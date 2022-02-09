# Note

## Baseline Function

這個題目是要我們找出一個字串中的最長回文字串，所謂的回文字串就是左右對稱的字串。由於回文字串的中心一定也會有對稱的性質，因此我在一開始先走過整個字串，找出所有對稱的中心點。其中的回文子字串又分為以下兩種，因此使用兩個不同的物件來儲存對稱的中心點：
1. 奇數回文字串：`i-1`跟`i+1`的字元相同。
2. 偶數回文字串：`i`跟`i+1`的字元相同。

函數中使用一個字串`currentLongestString`來紀錄最長子字串，一開始初始化為空字串。在找出所有回文字串的中心點之後，分成奇數、偶數的回文字串去看各個中心點往外看有多少組對稱字元，如果加入對稱的話就把當前字串`currentString`更新。若`currentString`大於`currentLongestString`則將`currentLongestString`取代為`currentString`。

![](https://i.imgur.com/5aQLvYX.png)

## Dynamic Programming

這個方法的概念其實跟我想的方法差不多，但是他使用Dynamic Programming的概念從長度為1到長度為n的子字串慢慢檢查，使用這種方法在檢查"abcba"時，由於更短的子字串"bcb"已經檢查完了，因此只要看"bcb"是不是回文字串、開頭結尾字元是否相同即可確定"abcba"是否為回文字串。

![](https://i.imgur.com/XXGE8mq.png)
