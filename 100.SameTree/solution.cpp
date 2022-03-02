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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p && q) {
            if (p->val != q->val) return false;
            
            bool same;
            if (p->left && q->left) same = isSameTree(p->left, q->left);
            else if (!p->left && !q->left) same = true;
            else same = false;

            if (p->right && q->right) same &= isSameTree(p->right, q->right);
            else if (!p->right && !q->right) same &= true;
            else same &= false;
            
            return same;
        }
        else return false;
    }
};