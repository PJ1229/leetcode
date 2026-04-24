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

I USED OUTSIDE RESOURCES TO SOLVE THIS. REDO LATER

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]

deque = {1}

iterate through nums

nums = 3 4 2 5 4 5 1 2 1 1 
k = 4

output = {4, 3, 2}

use heap

std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // nums = [1,1,1,2,2,3]

        unordered_map<int, int> hash; // num count

        for(auto i : nums) {
            hash[i]++;
        }

        /*
        freq = {
            1 → 3
            2 → 2
            3 → 1
        }
        */
        vector<vector<int>> bucket(nums.size() + 1); 
        // frequency table

        for(auto& [num, count] : hash) {
            bucket[count].push_back(num);
        }

        vector<int> output;

        // not O(n^2) since it runs the exact time as there are elts n
        for(int i = bucket.size() - 1; i >= 0; i--) {
            for(int num : bucket[i]) {
                output.push_back(num);
                if(output.size() == k)
                    return output;
            }
        }

        return output;
    }
};