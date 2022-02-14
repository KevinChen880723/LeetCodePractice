# Note

## Solution

這題是要判斷輸入字串中的所有括號順序是否正確，若正確則回傳`true`，反之回傳`false`。我的做法使用了Stack，如果遇到左括號就將該字元Push到Stack中，如果遇到右括號的話就去Stack中看最上面是否為其對應的左括號，假如不是的話則判斷輸入的字串為非法字串。

### 具體做法

#### 自定義Stack類別

使用Linked List創建一個叫做`Stack`的類別，裡面有以下三個成員方法：
1. `bool isEmpty()`：判斷Stack是否為空。
2. `void push(char d)`：將字元`d` push到Stack中。
3. `char pop(char source)`：傳入字元`source`，這個字元會是右括號，在這個成員方法中會去判斷Stack中最上面的資料是否為輸入右括號對應的左括號，如果是的話就將最上面的節點Pop掉；反之，假如不是正確的資料就回傳字元`F`。

#### Top Function

具體作法跟一開始的描述相同，但為了處理邊界條件，遇到右括號的時候要先判斷Stack裡面是否有資料，如果沒有的話就一定錯誤回傳`false`；在處理完所有字元時，判斷Stack是否為空，如果不是空的話就代表出現了不成對的括號，因此回傳`false`。

<img width="746" alt="圖片" src="https://user-images.githubusercontent.com/55487740/153802665-1fcb89d3-d107-4f91-a1a5-ddfc0601b772.png">
