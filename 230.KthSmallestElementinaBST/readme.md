# Note

這題給我們一個Binary Search Tree，叫我們從中找到樹裡面第`k`小的數值。

## My Solution

我使用遞迴的方式來完成這題，這個遞迴的程式會去看每個子樹的左右子樹分別有多少節點，並且回傳可能的第`k`小數值。看每個子樹的時候，我們會先去看左子樹再看中間節點，最後再看右子樹。
由於每次都會回傳子樹有多少節點，因此如果：
- 發現左子樹的節點數量超過`k`，就代表目標數值出現在左子樹，因此這時候遞迴程式回傳的結果即是正確結果。
- 左子樹走完之後再把累計節點數量的變數加一，代表中間的節點。加完之後再判斷節點數量是否為`k`，若結果為`k`則代表當前節點的數值即為目標，可以直接回傳。
- 假如右子樹的節點數量超過`k`，就代表目標數值出現在右子樹，因此這時候遞迴程式回傳的結果即是正確結果。

我這個方法的時間複雜度應該是`O(H+k)`，`H`代表樹的高度。因為當我找到第`k`小的數值時，就不會再繼續往更大的地方搜尋了。

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

## First LeetCode Solution

這個做法非常的直覺，直接使用Inorder traversal去取得樹中由小到大排序的數列，之後回傳第`k`個數值。這邊取得由小排到大的序列的方法為：回傳每個子樹由小排到大的數列，之後把左子樹、中間數值，以及右子樹的數列串接起來，最後就是完整的排序數列了。其中如果左右子樹為空，則直接回傳空串列，這樣當我們Traverse到Leaf node時，他的排序數列就只會有根節點的數值。

這樣解法的時間複雜度為`O(n)`，因為需要把每個節點都看一遍才有辦法完成Inorder traversal。

```python
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def inorder(r):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
    
        return inorder(root)[k - 1]
```

## Second LeetCode Solution

我覺得第二種作法跟我的想法很像，他是第一種作法的改版，在找到第`k`小的數值後就直接回傳，因此可以避免Traverse所有節點。

他使用Iterative的方式搭配Stack實現。每到一個新節點的時候，都直接往最左邊走到底，並且在移動前先將當前根節點存進Stack中，這樣才可以在走完左邊所有節點時，回到根節點。當所有左邊節點都看完，這時候就代表回到根節點了，也就是左子樹是空的（走到最左邊了），或者是左子樹Traverse完了（找到了做子樹以外最小的數值），因此將`k`減一。由於我們每找到一個新的最小值，都會將`k`減一，因此如果`k`等於零的時候就代表我們已經找到目標數值了。假如還沒的話再繼續往右子樹Traverse，當他Traverse完，當前子樹就都看完了，因此可以回到前一層。

```python
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        stack = []
        
        while True:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if not k:
                return root.val
            root = root.right
```
