#include "validateBinarySearchTree.h"
#include <cmath>

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

