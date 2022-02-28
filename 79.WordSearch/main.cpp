#include "wordSearch.cpp"
#include <iostream>

using namespace std;

int main(){
    Solution solution;
    // char ary[][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // char ary[][4] = {{'a'}};
    // char ary[][4] = {{'a'}, {'a'}};
    char ary[][4] = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};

    vector<vector<char> > board;
    int x, y;
    for (y = 0; y < 3; y++){
        vector<char> row;
        for (x = 0; x < 4; x++){
            row.push_back(ary[y][x]);
        }
        board.push_back(row);
    }
    bool result = solution.exist(board, "ABCESEEEFS");
    cout << result << endl;
    return 0;
}