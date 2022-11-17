# Note

這題很簡單，就是要我們把Binary tree左右反轉過來。我的解法很直接，就是用遞迴的方式，分別將存在的左右子樹反轉，接著再把當前`root`底下的`left`跟`right`交換。

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        if (root->left) root->left = invertTree(root->left);
        if (root->right) root->right = invertTree(root->right);
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        return root;
    }
};
```

![圖片](https://user-images.githubusercontent.com/55487740/202459701-605cb744-c34e-4e0a-b413-ac3d70f89a86.png)
