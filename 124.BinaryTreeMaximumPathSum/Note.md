# Note

這題給我們一個Binary Tree，希望我們在各個點都不重複的情況下找出總和最高的路徑。

## My Solution

我使用遞迴的方式來解這題，先找出子樹中的最大路徑，之後再透過子樹的最大路徑來取得整棵樹的真正最大路徑。為了避免找到重複的路徑，對於一個子樹來說我除了使用`currentMax`來記錄當前子樹可形成的最大路徑外，我還使用`composibleMax`來記錄當前子樹中還可以跟別人組合的最大路徑是多少。在找出子樹的`currentMax`及`composibleMax`以後，再去看整棵樹的`currentMax`及`composibleMax`是多少，計算方式為：
- `currentMax`：分別看左子樹及右子樹的`currentMax`，整體的最長路徑可以是左邊的`currentMax`，也可以是右邊的`currentMax`，或者有可能是由左右`composibleMax`組成的路徑。其中由於`composibleMax`有可能小於零，因此還要分別去看是只將左邊加根節點大，還是只拿右邊來加根節點大，又或者是兩個都要加再加上根節點比較大。
- `composibleMax`：整體的`composibleMax`只能是左子樹或右子樹的`composibleMax`再加上根節點，不然如果將這兩個加起來，之後就無法再跟父節點結合了。因此作法為比較左、右邊的`composibleMax`大小，選擇大的。之後還可以跟根節點合併，不過如果左或右邊的`composibleMax`都小於零，這樣不管選擇哪個跟根節點相加都會比根節點本身還小，因此這種情況就直接將`composibleMax`更新為根節點的數值。

```cpp
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int currentMax, composibleMax;
        maxPathSum(root, currentMax, composibleMax);
        return currentMax;
    }
    
    void maxPathSum(TreeNode* root, int &currentMax, int &composibleMax){
        currentMax = root->val;
        composibleMax = 0;
        int composible_left = 0, composible_right = 0;
        int currentMax_left = 0, currentMax_right = 0;
        
        if (root->left && root->right) {
            maxPathSum(root->left, currentMax_left, composible_left);
            maxPathSum(root->right, currentMax_right, composible_right);
            currentMax = max(currentMax_left, 
                            max(currentMax_right, 
                            max(composible_left+composible_right+root->val, 
                            max(composible_left+root->val, 
                            max(composible_right+root->val, root->val)))));
                            
            composibleMax = max(composible_left, composible_right);
            composibleMax = (composibleMax < 0)? root->val: composibleMax+root->val;
        }
        else if (root->left && !root->right) {
            maxPathSum(root->left, currentMax_left, composible_left);
            composibleMax = (composible_left < 0)? root->val: composible_left+root->val;
            currentMax = max(currentMax_left, composibleMax);
        }
        else if (!root->left && root->right) {
            maxPathSum(root->right, currentMax_right, composible_right);
            composibleMax = (composible_right < 0)? root->val: composible_right+root->val;
            currentMax = max(currentMax_right, composibleMax);
        }
        else {
            currentMax = root->val;
            composibleMax = root->val;
        }
    }
};
```

<img width="559" alt="圖片" src="https://user-images.githubusercontent.com/55487740/157367758-dfdc7477-b462-4164-9cce-1da2d198abab.png">

## 花花醬的作法

他的作法跟我差不多，不過程式寫的比較簡短，以下是他的程式：

```cpp
// Author: Huahua
// Runtime: 19 ms
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
private:
    int maxPathSum(TreeNode* root, int& ans) {
        if (!root) return 0;
        int l = max(0, maxPathSum(root->left, ans));
        int r = max(0, maxPathSum(root->right, ans));
        int sum = l + r + root->val;
        ans = max(ans, sum);
        return max(l, r) + root->val;
    }
};
```
