/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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