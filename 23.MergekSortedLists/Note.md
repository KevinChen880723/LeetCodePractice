# Note

## Solution

這題要將`k`個已經排序完的Linked List合併成一個大的List，最笨的方法就是每次都花`O(k)`的時間去看哪個List有當前最小值，之後再將他的第一個節點加到用來合併的List，不過這樣假如一個List的長度是`N`，那麼時間複雜度就會變成`O(kN)`。為了節省時間，我使用Min-heap的方式來記錄各個List的Header，假如Header的資料越小就放在越頂端，使用這樣的方式每次只需要`O(logk)`的時間就可以找到最小的Node，整體時間複雜度就會變成`O(klogN)。
具體方法為：
1. 先建立Heap的類別（其實C++有提供，這次只是為了練習才手刻）。
2. 之後每次從Heap中pop出一筆資料，由於Heap裡面存放的是各個List的Header Node，因此可以直接將這個Node加入`combinedList`中。這個過程我採用先前寫的`moveNodeToCombinedList()`函數來將新的節點加入`combinedList`，執行完之後會將指向第一個節點的指標改成指向第二個節點。
3. 在剛剛Pop完之後，Heap中就不會再有指向剛剛那個List的指標。因此需要再去檢查剛剛那個List中還有沒有節點，如果有的話再花`O(logk)`的時間將新的Header Node加入Heap中。
4. 重複以上步驟，直到Heap中不再有資料。

<img width="614" alt="圖片" src="https://user-images.githubusercontent.com/55487740/154214507-5de62ac0-edca-4518-a118-8822c4816fee.png">
