class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        return searchFrom(visited, grid);
    }
    void goTroughConnected(vector<vector<bool>> &visited, vector<vector<char>>& grid, int x, int y) {
        int i;
        int H = visited.size(), W = visited[0].size();
        if ((x < 0) || (x >= W) || (y < 0) || (y >= H)) return;
        if (visited[y][x] == 1 || grid[y][x] == '0') return;
        visited[y][x] = 1;
        for (i = 0; i < 4; i++) {
            goTroughConnected(visited, grid, x + move_dirs[i][1], y + move_dirs[i][0]);
        }
    }
    int searchFrom(vector<vector<bool>> &visited, vector<vector<char>>& grid) {
        int H = visited.size(), W = visited[0].size();
        int count = 0, x, y;
        // 跑過每一個點
        for (y = 0; y < H; y++) {
            for (x = 0; x < W; x++) {
                // 由於我們已經將之前有連接的島都標記為visited，因此如果遇到沒有標記visited的島就是新的島
                // 如果遇到陸地，就去看他有沒有被走過
                if (grid[y][x] == '0' || visited[y][x] == 1) continue;
                // 由於到了一個沒去過的島，因此島的數量加一
                count++;
                // 接著去把該陸地相連的所有陸地都標記為visited
                goTroughConnected(visited, grid, x, y);  
            }
        }
        return count;
    }
private:
    vector<vector<int>> move_dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
};