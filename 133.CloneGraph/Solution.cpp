#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> dict;
        return cloneGraph(node, dict);
    }
    
    Node* cloneGraph(Node *node, unordered_map<int, Node*> &dict) {
        Node *newNode = new Node(node->val);
        dict[node->val] = newNode;
        int i;
        for (Node *n : node->neighbors) {
            if (!dict.count(n->val)) dict[n->val] = cloneGraph (n, dict);
            newNode->neighbors.push_back(dict[n->val]);
        }
        return newNode;
    }
};