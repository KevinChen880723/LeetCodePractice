# Note

## Baseline Solution 

這題要我們將矩陣中包含零的行、列全部清除為零，我的作法是先採用`set`將所有包含零的行、列以不重複的方式紀錄，之後先刪除包含零的所有列再刪除所有包含零的行。不過為了避免重複歸零相同的資料，我一開始先去看有哪些列已經歸零了，之後建立一個還沒歸零的清單`havntZeroedRow`，回圈裡面就只需要針對這些資料歸零。此方法的空間複雜度為`O(m+n)`。

![](https://i.imgur.com/adWFMvV.png)

## Efficient Space Solution

其實這題的記憶體使用量可以再進一步下降，本來我使用兩個陣列來存紀錄需要歸零的行、列，但其實兩個陣列可以直接使用`matrix[y][0]`、`matrix[0][x]`取代。具體方式為：去看矩陣內的所有內容，如果資料為`0`就將它對應到的`matrix[y][0]`、`matrix[0][x]`設定為`0`。但使用這個方法需要特別注意第`0`行、第`0`列都會對應到`matrix[0][0]`，因此需要定義他只負責第`0`行**或**第`0`列的標記，另外一個則使用額外的布林變數紀錄。紀錄完成後就可以再去看所有的資料，假如他們對應到的`matrix[y][0]`或`matrix[0][x]`為`0`，就將它清為`0`，接著再分別看`matrix[0][0]`以及額外定義的布林變數是標記第一行或第一列是`0`，如果有的話再去將該行或列清除為`0`。此方法的空間複雜度為`O(1)`。

<img width="683" alt="圖片" src="https://user-images.githubusercontent.com/55487740/155682300-cec7abc3-4514-425d-8808-cdc350baa942.png">
