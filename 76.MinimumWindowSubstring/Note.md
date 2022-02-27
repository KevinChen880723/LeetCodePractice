# Note

## Baseline Solution

這題給定我們兩個字串`S`、`T`，他要我們在`S`字串中找出包含`T`的最小子字串（如果`T`中包含重複的字元，`S`也要包含至少一樣多的該字元）。這是我自己的作法，時間複雜度為`O(n)`，作法為：
1. 使用Hash map來對應字串`T`中所有字元出現的次數`num`、存放各個字元出現位置的`posList`。除此之外，再另外使用一個變數`currentDesiredAmount`來紀錄當前還需要幾個字串`T`中的字元。
2. 如果在尋找過程中找到一個字元，就要將對應的字元數量減一，並且也要將新的位置加入紀錄位置的`posList`中。這邊要注意的是：對於各個字元來說，當他對應的數字`num`為零的時候就代表我們已經成功找到目標數量的該字元，因此如果又遇到一樣的字元，就將最一開始遇到的移除，之後才加入新的位置；不過如果`num`還沒歸零的話，則可以直接加入。除了前面提到的更新`num`、`posList`以外，還要更新`currentDesiredAmount`。由於`num`在等於零的時候代表我們不再缺這個字元，在大於零的時候代表我們缺幾個該字元，因此我們只有在`num`不為零時才可以將`currentDesiredAmount`減一，
3. 如果`currentDesiredAmount`為零就代表我們找到一個符合規範的子字串，這時候就可以去看他的長度，如果他的長度比原本的還小的話，就將`currentBestSubString`更新為新的子字串。

我這個做法麻煩的點其實是在於怎麼在`O(1)`的時間找出子字串的開頭Index，原因是我使用一個Hash map來對應各個字元出現的位置，在這樣的情況下不同字元出現的位置會被分散在各個列表中，很難快速在當中找出最小的。一開始的作法比較笨，需要花費`O(T)`的時間去一一查看各個字元出現的第一個位置，取當中最小的。不過後來想到一個比較好的方式，可以在`O(1)`的時間達成目標，此方式使用`firstIdxOfSubString`來紀錄當前子字串最前面的位置，這裡比較需要思考的是如何在第一個字元被移除後將`firstIdxOfSubString`更新為第二個字元出現的位置。為了做到這個效果，我使用Double Linked List的概念，建立一個長度與`S.size()`相同的陣列`relationship`，陣列每個位置存放各個位置在子字串中的前一個及後一個字元出現的位置，例如：`"ADOBEC"`中的`A`、`B`、`C`是目標字元，那麼`relationship[3].first`就會是`0`，而`relationship[3].second`就會是`5`。在更新子字串的同時更新`relationship`，假如有人被刪除，就將它前面的人指到他後面，將他後面的人指到他前面。有了`relationship`之後我們就可以知道當前第二個出現的位置為`relationship[firstIdxOfSubString].second`。

<img width="715" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155848255-0316e064-fe97-4edf-9df6-42afbc6cd86c.png">

## Two Pointers Solution

這個是LeetCode官方提供的解法，這個作法跟我一樣都是`O(n)`，不過他的思路比較直覺。他的大概念為：使用兩個指標`l`、`r`，每次都去移動`r`，若找到包含所有字串`t`中的字元，就去更新當前最短子字串。由於他的方法都是在固定`l`的情況下移動`r`，因此`l`的位置不一定可以產生最好的結果，在這樣的情況下如果要找出符合條件的最短子字串，就要再接著慢慢地移動`l`指標，當他移動到子字串不再符合條件時，我們再去移動指標`r`尋找下一個符合條件的子字串。重複以上動作，直到`r`已經看完字串`s`中的所有字元。在這個方法中我們有提到要去檢查子字串是否符合條件，不過這個演算法是如何使用`O(1)`的時間完成檢查呢？一開始他先去看字串`t`中的各個字元分別出現幾次，並且使用一個Hash Map `dict_target_num`來做紀錄；另外，使用`numDesiredUniqueChar`來紀錄字串`t`中有幾個Unique的字元；使用`numAlreadyHaveUnique`來紀錄我們目前已經找完幾組字元。之後在每次找到一個位於`dict_target_num`中的字元時，就去看我們目前一共找到幾個該字元，如果已經找到`dict_target_num`要求的數量，就代表我們已經找到符合條件數量的該字元，因此可以將`numAlreadyHaveUnique`加一，假如`numAlreadyHaveUnique`等於`numDesiredUniqueChar`，就代表當前的子字串符合條件。

<img width="742" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155886800-20e78640-bf0b-44f7-b413-b2f7502deb5b.png">
