# Note

這題給我們一個Binary Tree，希望我們在各個點都不重複的情況下找出總和最高的路徑。

## My Solution

我使用遞迴的方式來解這題，先找出子樹中的最大路徑，之後再透過子樹的最大路徑來取得整棵樹的真正最大路徑。為了避免找到重複的路徑，對於一個子樹來說我除了使用`currentMax`來記錄當前子樹可形成的最大路徑外，我還使用`composibleMax`來記錄當前子樹中還可以跟別人組合的最大路徑是多少。在找出子樹的`currentMax`及`composibleMax`以後，再去看整棵樹的`currentMax`及`composibleMax`是多少，計算方式為：。
