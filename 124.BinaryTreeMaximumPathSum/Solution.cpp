#include <iostream>
#include <vector>
#include <algorithm>

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