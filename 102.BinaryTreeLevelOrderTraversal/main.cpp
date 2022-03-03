#include "BT.h"
#include "levelOrder.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    BinaryTree bt("1,2,3,4,null,null,5");
    Solution solution;
    vector<vector<int> > result = solution.levelOrder(bt.root);
    int i, j;
    cout << "[";
    for (i = 0; i < result.size(); i++){
        vector<int> n = result[i];
        cout << "[";
        for (j = 0; j < n.size(); j++){
            cout << n[j];
            if (j != n.size()-1) cout << ", ";
        }
        cout << "]";
        if (i != result.size()-1) cout << ", ";
    }
    cout << "]";
        
    return 0;
}