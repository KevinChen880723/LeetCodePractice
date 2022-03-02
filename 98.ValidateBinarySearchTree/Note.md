# Note

題目給我們一個Binary Tree要我們去判斷他是否為有效的Binary Search Tree。

## My Solution

一開始沒想太多就覺得對於每個點都去跟左右子節點比，root一定要比左節點大，一定要比右節點小，不過這個做法沒辦法考慮到所有情況，原因是有時候雖然拿root跟他他自己的左右節點比較可以得到正確結果，但可能再往下多看起層就不準了。例如：下圖的錯誤就不會被檢查出來。

![](https://i.imgur.com/QzcMTfr.png)

後來我的作法變成從最下面慢慢抓最小、最大值，並且從下往上的過程中慢慢地更新這個最小、最大值，對於每個節點都去看當前數值有沒有比左子樹的最大值還大、有沒有比右子數的最小值小。

```cpp
struct result{
    int smallest;
    int largest;
    bool valid;
};

result checkBST(TreeNode *root){
    result returnValue;
    if (root->left && root->right) {
        result rightResult = checkBST(root->right);
        result leftResult = checkBST(root->left);
        returnValue.valid = root->val > leftResult.largest && root->val < rightResult.smallest 
                         && rightResult.valid && leftResult.valid;
        returnValue.largest = max(max(rightResult.largest, leftResult.largest), root->val);
        returnValue.smallest = min(min(rightResult.smallest, leftResult.smallest), root->val);
    }
    else if (!root->left && root->right) {
        result rightResult = checkBST(root->right);
        returnValue.valid = root->val < rightResult.smallest && rightResult.valid;
        returnValue.largest = max(root->val, rightResult.largest);
        returnValue.smallest = min(root->val, rightResult.smallest);
    }
    else if (root->left && !root->right) {
        result leftResult = checkBST(root->left);
        returnValue.valid = root->val > leftResult.largest && leftResult.valid;
        returnValue.largest = max(root->val, leftResult.largest);
        returnValue.smallest = min(root->val, leftResult.smallest);
    }
    else {
        returnValue.largest = root->val;
        returnValue.smallest = root->val;
        returnValue.valid = true;
    }
    return returnValue;
}

bool Solution::isValidBST(TreeNode* root){
    return checkBST(root).valid;
}
```

## 別人的另一種做法

- 他的作法還滿直覺的，二元搜尋樹中每個節點都會有他合理的範圍，每次往下地回的時候就去調整這個範圍，假如某個節點的數值超過該範圍，就直接回傳`false`；反之，如果沒超過範圍就再繼續往下遞迴做檢查。
- [網址](https://zxi.mytechroad.com/blog/tree/leetcode-98-validate-binary-search-tree/)

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, long min_val, long max_val) {
        if (!root) return true;
        if (root->val <= min_val || root->val >= max_val)
            return false; 
        return isValidBST(root->left, min_val, root->val)
            && isValidBST(root->right, root->val, max_val);
    }
};
```

## Inorder Traversal的作法

- 正常Inorder Traversal的結果應該會按照大小排序，因此我們其實可以去執行Inorder Traversal，之後拿每個節點跟前一個節點比較，假如發現後面的資料比前面的小，就代表該二元樹為非法二元搜尋樹。
- [網址](https://zxi.mytechroad.com/blog/tree/leetcode-98-validate-binary-search-tree/)

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        prev_ = nullptr;
        return inOrder(root);
    }
private:
    TreeNode* prev_;
    bool inOrder(TreeNode* root) {
        if (!root) return true;
        if (!inOrder(root->left)) return false;
        if (prev_ && root->val <= prev_->val) return false;    
        prev_ = root;
        return inOrder(root->right);
    }
};
```
