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
sum of all three nums i,j,k must equal 0
find all combinations that can result in this

two pointer problem
two sum:


another thought: sort first, then use left and right pointers
> result in O(nlogn) time complexity

map
index : compliment

[-1,0,1,2,-1,-4] > [-4,-1,-1,0,1,2]

we insert the compliments first

maybe it cant be solved in O(nlogn) since it needs to be an exhaustive list
lets figure out a O(n^2) solution given the first hint
fix x

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate values for the fixed element
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // Early exit: if smallest possible sum > 0, no solution exists
            if (nums[i] > 0) break;

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    out.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicates on both sides
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++; right--;
                } else if (sum < 0) {
                    left++;   // need larger sum
                } else {
                    right--;  // need smaller sum
                }
            }
        }
        return out;
    }
};
