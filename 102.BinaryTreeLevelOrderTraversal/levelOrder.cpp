#include "levelOrder.h"

void Solution::levelOrder(vector<vector<int> > &result, vector<int> &result_sameLayer, queue<nodeWithLevel> &q, int lastLevel) { 
    if (q.size() != 0) {
        nodeWithLevel root = q.front();
        q.pop();
        if (root.level != lastLevel) {
            result.push_back(result_sameLayer);
            result_sameLayer.clear();
        }
        result_sameLayer.push_back(root.node.val);
        if (root.node.left) q.push(nodeWithLevel(*(root.node.left), root.level+1));
        if (root.node.right) q.push(nodeWithLevel(*(root.node.right), root.level+1));
        if (!root.node.left && !root.node.right && q.size() == 0) result.push_back(result_sameLayer);
        levelOrder(result, result_sameLayer, q, root.level);
    }
}

vector<vector<int> > Solution::levelOrder(TreeNode* root) {
    if (!root) return vector<vector<int> >();
    vector<vector<int> > result;
    vector<int> result_sameLayer;
    queue<nodeWithLevel> q;
    q.push(nodeWithLevel(*root, 0));
    levelOrder(result, result_sameLayer, q, 0);
    return result;
}