/*
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Formula: index = (y * width) + x.
Reverse: x = index % width and y = index / width.
*/

class Solution {
public:

    // Formula: index = (y * width) + x.
    int encodeCoords(vector<vector<char>>& grid, int m, int n) {
        if(grid.size() == 0) return 0;
        return (n * grid[0].size()) + m;
    }

    // Reverse: x = index % width and y = index / width.
    pair<int, int> decodeCoords(vector<vector<char>>& grid, int index) {
        if(grid.size() == 0) return {-1, -1};
        int x = index % grid[0].size();
        int y = index / grid[0].size();
        return {x, y};
    }

    void bfs(vector<vector<char>>& grid, int m, int n, unordered_set<int>& visited) {
        //instead of using pair we can calculate location using m*grid.size() + n
        queue<int> path;

        int root = encodeCoords(grid, m,n);
        visited.insert(root);
        path.push(root);

        int rows = grid.size();
        int cols = grid[0].size();
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!path.empty()) {
            auto [x, y] = decodeCoords(grid, path.front());
            path.pop();
            
            for(auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < 0 || nx >= cols || ny < 0 || ny >= rows) continue;
                if (grid[ny][nx] != '1') continue;
                int encoded = encodeCoords(grid, nx, ny);
                if (visited.count(encoded)) continue;
                visited.insert(encoded);
                path.push(encoded);
            }
        }

    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        unordered_set<int> visited;
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                int encoded = encodeCoords(grid, j, i);
                if(grid[i][j] == '1' && !visited.count(encoded)) {
                    islands++;
                    bfs(grid, j, i, visited);
                }
            }
        }

        return islands;
        
    }
};