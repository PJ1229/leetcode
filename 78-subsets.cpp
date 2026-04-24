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

class Solution {
public:

    void backtrack(int i, vector<int>& nums, vector<int>& current, vector<vector<int>>& out) {
        if(i == nums.size()) {
            out.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        backtrack(i+1, nums, current, out);

        current.pop_back();

        backtrack(i+1, nums, current, out);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> current;
        backtrack(0, nums, current, out); //0, [1,2], [], []
        return out;
    }
};