#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 1;
        if (!root) return 0;
        dfs(root, 1, maxDepth);
        return maxDepth;
    }
    
    void dfs(TreeNode *root, int level, int &maxDepth){
        maxDepth = max(maxDepth, level);
        if (root->left) dfs(root->left, level+1, maxDepth);
        if (root->right) dfs(root->right, level+1, maxDepth);
    }
};