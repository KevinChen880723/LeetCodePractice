class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> results;
        for (string word : words) {
            // find the first letter of word in the board and search word from there if the position is containing the first letter of word
            bool findWord = false;
            for (int y = 0; y < board.size(); y++) {
                for (int x = 0; x < board[0].size(); x++) {
                    if (board[y][x] == word[0]) {
                        // find from all its neighbors
                        if (word.size() == 1 || findWordsFrom(board, word.substr(1), vector<int>{y, x})) {
                            findWord = true;
                            break;
                        }
                    }
                }
                if (findWord) break;
            }
            if (findWord) results.push_back(word);
        }
        return results;
    }
private:
    int neighborDirs[4][4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool findWordsFrom(vector<vector<char>>& board, string word, const vector<int> &startFrom) {
        int y = startFrom[0], x = startFrom[1];
        bool returnValue = false;
        char temp = board[y][x];
        board[y][x] = '.';

        // find sub-string from all its neighbors
        for (int d = 0; d < 4; d++) {
            int next_x = x + neighborDirs[d][1], next_y = y + neighborDirs[d][0];
            if (next_x < 0 || next_x >= board[0].size() || next_y < 0 || next_y >= board.size()) continue;

            if (board[next_y][next_x] == word[0]) {
                if (word.size() == 1 || findWordsFrom(board, word.substr(1), vector<int>{next_y, next_x})) {
                    returnValue = true;
                    break;
                }
            }
        }
        // change the char in the current position back
        board[y][x] = temp;
        return returnValue;
    }
};