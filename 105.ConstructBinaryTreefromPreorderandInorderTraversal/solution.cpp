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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, make_pair<int, int>(0, preorder.size()-1), make_pair<int, int>(0, inorder.size()-1));
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, pair<int, int> range_preorder, pair<int, int> range_inorder){
        int vecSize = range_preorder.second - range_preorder.first + 1;
        if (vecSize == 0) return nullptr;
        int currentVal = preorder[range_preorder.first];
        TreeNode *root = new TreeNode(currentVal);
        
        int pos_currentValInorder = int(find(inorder.begin(), inorder.end(), currentVal) - inorder.begin());
        int size_leftTree = pos_currentValInorder - range_inorder.first;
        if (pos_currentValInorder+1 <= range_inorder.second){
            root->right = buildTree(preorder, inorder, make_pair(range_preorder.first+size_leftTree+1, range_preorder.second), make_pair(pos_currentValInorder+1, range_inorder.second));
        }
        if (pos_currentValInorder > range_inorder.first){
            root->left = buildTree(preorder, inorder, make_pair(range_preorder.first+1, range_preorder.first+1+size_leftTree), make_pair(range_inorder.first, pos_currentValInorder-1));
        }
        
        return root;
    }
};