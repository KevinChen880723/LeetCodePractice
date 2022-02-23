# Note

## Baseline Solution

這題給我們一個數列，數列中任意位置的數字代表到該位置後可以移動幾步，題目問我們能不能成功走到終點。Baseline是我一開始的作法，我在每一步的時候都去檢查他可以走到的範圍內的那一個位置可以再走到最遠，之後就選擇移動到該位置。這個方法雖然可以成功，但是因為在每一步都要去檢查周圍的那一不可以走到最遠，假如每個位置都可以移動很多步，但可以移動最遠的剛好都在離自己最近的位置，那這樣每一步最多都有可能要檢查`n`個鄰居，總共有`n`個點的話總時間複雜度就是`O(n^2)`。

<img width="673" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155265526-6245c222-e620-4ac7-8323-1d2227bcd9a6.png">

將程式改成下面這樣可以讓運行時間大幅下降，這樣改的原因是：本來每到新的地方都要在檢查所有鄰居，但是其實有些人已經在上一步就已經檢查過了沒必要再檢查，因此我使用`alreadyCheckedRange`變數來紀錄之前檢查到哪些範圍，之後下一步就不要再檢查該範圍內的資料。可以發現經過這樣的修改後，可以達到PR78。

![圖片](https://user-images.githubusercontent.com/55487740/155265626-2a6076d0-05d5-4115-bab1-998ed096f774.png)

<img width="656" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155265487-f74c0622-f045-4818-9769-03439b3baa52.png">

## Better Solution

這是隔天來實驗室才想到的方法，一開始竟然沒辦法馬上想到ＱＱ
這個方法的時間複雜度為`O(n)`，使用一個for回圈從頭跑到尾，並且使用一個變數`currentAvailableTarget`來紀錄目前可以走到哪個位置，每到一個新的位置都檢查走到這邊之後有沒有辦法走到更遠的地方，如果可以的話就更新`currentAvailableTarget`。過程中如果for回圈在跑的變數`i`超過`currentAvailableTarget`，就代表我們其實是到不了這個位置的，因此直接回傳`false`，假如可以走到底就回傳`true`。

<img width="654" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155263969-f06c34a9-fb60-4f85-b1f0-040c1d3b6f55.png">
