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
nums = [2,7,11,15], target = 9
map
indice : value
0 : 2 
1 : 7 
2 : 11 
3 : 15 

target - 2 
7 : 
target - 7
2 : 
target - 11
-2 : 
target - 15
6 : 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> sum;
        for(int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            if (sum.find(compliment) != sum.end()) {
                return {sum[compliment], i};
            }
            sum[nums[i]] = i;
        }
        return {};
    }
};