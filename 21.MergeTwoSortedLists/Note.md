# Note

## Solution

這個程式很簡單，就去看兩個List到結尾沒，如果都還沒的話就比較當前哪個Node的資料比較小，將比較小的資料移到`combinedList`中；如果其中一個到結尾，另一個還沒的話，就將還沒到結尾的所有Node移動到`combinedList`中。

由於這題中會出現一堆重複的程式，因此我使用副程式`moveNodeToCombinedList`來將`targetNode`指向的Node搬移到`combinedList`的最後面。之所以使用雙重指標是因為我要指向的對象也是指標，如果副程式只單純使用指標的話會變成Call by Value，這樣改不到外面變數的數值。

> 為了方便測試，我另外建了一個名為`LinkedList`的類別，他只會在`main.cpp`中使用。

![](https://i.imgur.com/M1ql44w.png)
