# Note

## My Solution

這題就是要使用Level Order的方式來看過並回傳整棵樹的資料，他比較麻煩的是回傳的資料型態是二維的`vector`，裡面每一個`vector`代表每一層的資料。一般的Level Order Traversal可以使用簡易的Queue存放各個Node來完成，不過為了做到題目要求的效果，我的Queue除了存放各個Node以外，也會存放各個Node出現在第幾層。我的程式使用遞迴的方式實現，其中有一個參數`lastLevel`是代表上一個看的Node是在第幾層，假如當前Node的層數與上一層不同的話就把`result_sameLayer`加入`result`，要注意的是用這樣的方式最後一層的資料不會被加入`result`中，因此應該還要判斷左子樹、右子數及queue是否為空，如果為空的話再將`result_sameLayer`加入`result`一次。

<img width="679" alt="圖片" src="https://user-images.githubusercontent.com/55487740/156501661-cffd3680-ebc3-49bf-88c9-544a68f83001.png">

```cpp
vector<vector<int> > Solution::levelOrder(TreeNode* root) {
    if (!root) return vector<vector<int> >();
    vector<vector<int> > result;
    vector<int> result_sameLayer;
    queue<nodeWithLevel> q;
    q.push(nodeWithLevel(*root, 0));
    levelOrder(result, result_sameLayer, q, 0);
    return result;
}

void Solution::levelOrder(vector<vector<int> > &result, vector<int> &result_sameLayer, queue<nodeWithLevel> &q, int lastLevel) { 
    if (q.size() != 0) {
        nodeWithLevel root = q.front();
        q.pop();
        if (root.level != lastLevel) {
            result.push_back(result_sameLayer);
            result_sameLayer.clear();
        }
        result_sameLayer.push_back(root.node.val);
        if (root.node.left) q.push(nodeWithLevel(*(root.node.left), root.level+1));
        if (root.node.right) q.push(nodeWithLevel(*(root.node.right), root.level+1));
        if (!root.node.left && !root.node.right && q.size() == 0) result.push_back(result_sameLayer);
        levelOrder(result, result_sameLayer, q, root.level);
    }
}
```
