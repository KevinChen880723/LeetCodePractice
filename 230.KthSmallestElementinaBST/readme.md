# Note

這題給我們一個Binary Search Tree，叫我們從中找到樹裡面第`k`小的數值。

## My Solution

我使用遞迴的方式來完成這題，這個遞迴的程式會去看每個子樹的左右子樹分別有多少節點，並且回傳可能的第`k`小數值。看每個子樹的時候，我們會先去看左子樹再看中間節點，最後再看右子樹。
由於每次都會回傳子樹有多少節點，因此如果：
- 發現左子樹的節點數量超過`k`，就代表目標數值出現在左子樹，因此這時候遞迴程式回傳的結果即是正確結果。
- 左子樹走完之後再把累計節點數量的變數加一，代表中間的節點。加完之後再判斷節點數量是否為`k`，若結果為`k`則代表當前節點的數值即為目標，可以直接回傳。
- 假如右子樹的節點數量超過`k`，就代表目標數值出現在右子樹，因此這時候遞迴程式回傳的結果即是正確結果。

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int nodeMum = 0;
        return kthSmallestAndGetNodesNum(root, k, nodeMum);
    }

    int kthSmallestAndGetNodesNum(TreeNode* root, int k, int &numTreeNodes) {
        TreeNode *temp = root;
        if (temp->left) {
            int leftResult = kthSmallestAndGetNodesNum(temp->left, k, numTreeNodes);
            if (numTreeNodes >= k) return leftResult;
        }
        numTreeNodes++;
        if (numTreeNodes == k) return temp->val;
        if (temp->right) {
            int rightResult = kthSmallestAndGetNodesNum(temp->right, k, numTreeNodes);
            if (numTreeNodes >= k) return rightResult;
            else return -1;
        }
        else return -1;

    }
};
```

![圖片](https://user-images.githubusercontent.com/55487740/202613692-cf659422-5119-46f5-83ea-3d291295e975.png)
