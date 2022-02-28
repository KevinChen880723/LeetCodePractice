#include "wordSearch.h"
#include <unordered_map>
#include <unordered_set>

struct direction
{
    direction(int X, int Y): x(X), y(Y) {}
    int x;
    int y;
};

const direction dir[4] = {direction(-1, 0), direction(0, 1), direction(1, 0), direction(0, -1)};

bool searchFromStartPoint (vector<vector<char> >& board, string word, vector<vector<bool> > srcPath, int x, int y, int searchingIdx) {
    // Search four directions
    for (const direction d : dir){
        if (x+d.x < 0 || x+d.x > board[0].size()-1 || y+d.y < 0 || y+d.y > board.size()-1) continue;
        if (srcPath[y+d.y][x+d.x]) continue;
        if (board[y+d.y][x+d.x] == word[searchingIdx]) {
            if (searchingIdx == word.size()-1) return true;
            srcPath[y+d.y][x+d.x] = true;
            bool find = searchFromStartPoint (board, word, srcPath, x+d.x, y+d.y, searchingIdx+1);
            if (find) return true;
            srcPath[y+d.y][x+d.x] = false;
        }
    }
    // Doesn't find the word
    return false;
}

bool Solution::exist(vector<vector<char> >& board, string word){
    vector<vector<bool> > srcPath(board.size(), vector<bool>(board[0].size(), false));

    int x, y, d;
    for (y = 0; y < board.size(); y++){
        for (x = 0; x < board[0].size(); x++){
            if (board[y][x] == word[0]){
                srcPath[y][x] = true;
                if (word.size() > 1) {
                    bool find = searchFromStartPoint (board, word, srcPath, x, y, 1);
                    if (find) return true;
                }
                else return true;
                srcPath[y][x] = false;
            }
        }
    }
    return false;
}