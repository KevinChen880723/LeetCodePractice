#include "levelOrder.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class BinaryTree{
public:
    BinaryTree (string s) {
        stringstream ss(s);
        string word;
        vector<TreeNode> nodes;
        nodes.push_back(TreeNode(0));
        int i = 0;
        for (; getline(ss, word, ',');) {
            if (isNum(word))
                nodes.push_back(TreeNode(stoi(word)));
            else
                nodes.push_back(TreeNode(-1111));
        }
        if (nodes.size() == 0) root = nullptr;
        else{
            for (i = 1; i < nodes.size(); i++){
                if (i*2 < nodes.size()) {
                    if (nodes[i*2].val != -1111) nodes[i].left = &nodes[i*2];
                    else nodes[i].left = nullptr;
                }
                if (i*2+1 < nodes.size()) {
                    if (nodes[i*2+1].val != -1111) nodes[i].right = &nodes[i*2+1];
                    else nodes[i].right = nullptr;
                }
            }
        }
        root = &(nodes[1]);
        i = 0;
    }
    TreeNode *root;
private:
    struct Condition{
        bool operator()(char c){
            return isdigit(c) || c == '-';
        }
    };

    bool isNum(const std::string& s)
    {
        Condition condition;
        int num_digit =  count_if(s.begin(), s.end(), condition);
        return num_digit == s.size();
    }
};