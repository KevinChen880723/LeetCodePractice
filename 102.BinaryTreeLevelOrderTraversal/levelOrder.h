#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#ifndef LEVELORDER_H
#define LEVELORDER_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct nodeWithLevel{
    nodeWithLevel(TreeNode n, int l): node(n), level(l) {}
    TreeNode node;
    int level;
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root);
    void levelOrder(vector<vector<int> > &result, vector<int> &result_sameLayer, queue<nodeWithLevel> &q, int lastLevel);
};
#endif