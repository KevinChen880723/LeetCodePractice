# Note

這題給我們一個BST，要我們從中去找出某兩個節點的最小共同祖先節點（往上找第一個交會的點）。

## My Solution

我的作法是先在BST中找出兩個目標節點，並在找的過程分別記錄他們在Tree的第幾層，以及他們一路走下來遇到的祖先節點。接著先去判斷兩個節點的層數是否相同，沒有的話就先讓他們相同，假如相同的時候他們剛好對應在相同節點，就代表這是他們的最小共同祖先節點。假如他們曾數相同時，他們沒有在相同點，只能代表他們是Sibling nodes，要在網上繼續找共同祖先。
這樣的時間複雜度為`O(H)`，因為最多只會花費`O(2H)`的時間。

```cpp
class Solution {
public:
    void findNode(TreeNode* root, TreeNode *targetNode, int &level_counter, vector<TreeNode*> &stack) {
        TreeNode *temp = root;
        while (temp != targetNode) {
            level_counter++;
            stack.push_back(temp);
            if (targetNode->val > temp->val) temp = temp->right;
            else if (targetNode->val < temp->val) temp = temp->left;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> firstStack, secondStack;
        int first_level_counter = 0, second_level_counter = 0;
        TreeNode *firstPtr = p, *secondPtr = q; 
        findNode(root, p, first_level_counter, firstStack);
        findNode(root, q, second_level_counter, secondStack);
        while (first_level_counter > second_level_counter) {
            first_level_counter--;
            firstPtr = firstStack.back();
            firstStack.pop_back();
        }
        while (first_level_counter < second_level_counter) {
            second_level_counter--;
            secondPtr = secondStack.back();
            secondStack.pop_back();
        }
        while (firstPtr != secondPtr) {
            firstPtr = firstStack.back();
            secondPtr = secondStack.back();
            firstStack.pop_back();
            secondStack.pop_back();
        }
        return firstPtr;
    }
};
```

![圖片](https://user-images.githubusercontent.com/55487740/202651325-31dbb108-15a3-41bd-8649-2341ae571e8f.png)
