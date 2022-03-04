# Note

## Solution

由於Preorder的root node會在最前面；Inorder的root node會出現在中間，因此可以去Inorder list中搜尋Preorder的第一個數字，在這個數字左邊的都會被歸類在左子樹，反之則在右子數。整體程式使用遞迴的方式實現，該遞迴程式會回傳Sub-tree的root node，因此程式中先建立數值與root node相同的節點，之後再將左指標指向左子數的root node（呼叫遞迴程式），右指標指向右子數的root node（呼叫遞迴程式）。

![](https://i.imgur.com/LgUWQe2.png)
