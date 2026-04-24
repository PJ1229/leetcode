#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
start at the top left of the grid
iterate through
if hit a 1
    bfs fill the grid
    mark as visited
    store size
return max size

include decoder + encoder
*/

class Solution {
public:

    int encodeCoords(vector<vector<int>>& grid, int x, int y) {
        if(grid.size() == 0) return 0;
        return (y * grid[0].size()) + x;
    }

    pair<int, int> decodeCoords(vector<vector<int>>& grid, int index) {
        if(grid.size() == 0) return {-1, -1};
        int x = index % grid[0].size();
        int y = index / grid[0].size();
        return {x, y};
    }

    bool isValid(int rows, int cols, int x, int y) {
        return x >= 0 && x < cols && y >= 0 && y < rows;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        unordered_set<int> visited;

        int rows = grid.size();
        int cols = grid[0].size();

        int maxSize = 0;

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for(int y=0; y<rows; y++) {
            for(int x=0; x<cols; x++) {
                int size = 0;
                int encoded = encodeCoords(grid,x,y);
                if(!visited.count(encoded) && grid[y][x] == 1) {
                    size++;

                    queue<int> path;
                    visited.insert(encoded);
                    path.push(encoded);

                    while(!path.empty()) {

                        int temp = path.front();
                        path.pop();
                        for(auto& d : dir) {

                            int tempx = decodeCoords(grid, temp).first + d.first;
                            int tempy = decodeCoords(grid, temp).second + d.second;
                            int tempEncoded = encodeCoords(grid, tempx, tempy);

                            if(isValid(rows, cols, tempx, tempy) 
                                && !visited.count(tempEncoded)
                                && grid[tempy][tempx] == 1
                            ) {
                                path.push(tempEncoded);
                                visited.insert(tempEncoded);
                                size++;
                            }
                        }
                    }
                }
                maxSize = max(size, maxSize);
            }
        }

        return maxSize;
    }
};