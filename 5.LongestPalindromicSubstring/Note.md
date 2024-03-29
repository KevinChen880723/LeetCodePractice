# Note

## Baseline Function

這個題目是要我們找出一個字串中的最長回文字串，所謂的回文字串就是左右對稱的字串。由於回文字串的中心一定也會有對稱的性質，因此我在一開始先走過整個字串，找出所有對稱的中心點。其中的回文子字串又分為以下兩種，因此使用兩個不同的物件來儲存對稱的中心點：
1. 奇數回文字串：`i-1`跟`i+1`的字元相同。
2. 偶數回文字串：`i`跟`i+1`的字元相同。

函數中使用一個字串`currentLongestString`來紀錄最長子字串，一開始初始化為空字串。在找出所有回文字串的中心點之後，分成奇數、偶數的回文字串去看各個中心點往外看有多少組對稱字元，如果加入對稱的話就把當前字串`currentString`更新。若`currentString`大於`currentLongestString`則將`currentLongestString`取代為`currentString`。

```cpp
string Solution::longestPalindrome(string s) {
    int i;
    string currentLongestString("");

    vector<int> oddMirrorCenter, evenMirrorCenter;
    char last2Char = '!', lastChar = '!';
    for (i = 0; i < s.size(); i++){
        if (s[i] == lastChar) evenMirrorCenter.push_back(i);
        if (s[i] == last2Char) oddMirrorCenter.push_back(i-1);
        last2Char = lastChar;
        lastChar = s[i];
    }

    for (i = 0; i < oddMirrorCenter.size(); i++){
        int j = 1, center = oddMirrorCenter[i];
        string currentString;
        currentString.push_back(s[center]);
        if (currentString.size() > currentLongestString.size()) 
            currentLongestString = currentString;
        while (center-j >= 0 && center+j <= s.size()-1){
            if (s[center-j] == s[center+j]){
                currentString.insert(currentString.begin(), s[center-j]);
                currentString.push_back(s[center-j]);
                j++;
                if (currentString.size() > currentLongestString.size()) 
                    currentLongestString = currentString;
            }
            else break;
        }
    }

    for (i = 0; i < evenMirrorCenter.size(); i++){
        int j = 1, center = evenMirrorCenter[i];
        string currentString;
        currentString.insert(0, 2, s[center]);
        if (currentString.size() > currentLongestString.size()) 
            currentLongestString = currentString;
        while (center-j-1 >= 0 && center+j <= s.size()-1){
            if (s[center-j-1] == s[center+j]){
                currentString.insert(currentString.begin(), s[center-j-1]);
                currentString.push_back(s[center-j-1]);
                j++;
                if (currentString.size() > currentLongestString.size()) 
                    currentLongestString = currentString;
            }
            else break;
        }
    }

    if (currentLongestString == "") currentLongestString.push_back(s[0]);

    return currentLongestString;
}
```

![](https://i.imgur.com/5aQLvYX.png)

## Dynamic Programming

這個方法的概念其實跟我想的方法差不多，但是他改用Dynamic Programming的方式完成。使用Dynamic Programming時會Bottom-up地從長度為1到長度為n的子字串慢慢檢查，在檢查"abcba"時由於更短的子字串"bcb"已經檢查完了，因此只要看"bcb"是不是回文字串、開頭結尾字元是否相同即可確定"abcba"是否為回文字串。使用這種方法可以避免子字串的重複檢查，他可以做到O(n^2/2)的時間複雜度，但由於看時間複雜度時不看倍數，因此實際上還是O(n^2)。

```cpp
string Solution::longestPalindrome(string s){
    bool lookUpTable[s.size()][s.size()];
    int i, j, k;
    string longestString("");
    for (k = s.size(); k >= 1; k--){
        for (i = s.size()-k, j = 0; j < k; i++, j++){
            switch (i-j)
            {
            case 0:
                lookUpTable[j][i] = true;
                break;
            case 1:
                lookUpTable[j][i] = s[i] == s[j];
                break;
            default:
                lookUpTable[j][i] = lookUpTable[j+1][i-1] && s[i] == s[j];
                break;
            }
            if (lookUpTable[j][i] && (i-j+1) > longestString.size())
                longestString = s.substr(j, i-j+1); 
        }
    }
    return longestString;
}
```

> 雖然這邊跑起來時間看起來比較快，但我覺得這個速度跟使用的資料結構也有差。在Dynamic Programming中我使用二維陣列，但Baseline Function中使用vector，兩者的速度本身就有差。另外還有一點要注意的是：Leetcode每次跑的結果都不太一樣，我這兩個結果都是取好幾次裡面最快的結果，但其實有時候Dynamic Programming反而還比較慢。

![](https://i.imgur.com/2ADIdpB.png)
