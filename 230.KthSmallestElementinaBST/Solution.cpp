/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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