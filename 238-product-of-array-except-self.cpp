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
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

nums
[1,2,3,4]
pre
[1,1,2,6]
pref[i] = nums[i - 1] * pref[i - 1];
suff
[24,12,4,1]
suff[i] = nums[i + 1] * suff[i + 1];

prefix and suffix
cant use division operator
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size());
        vector<int> suff(nums.size());
        vector<int> output(nums.size());
        pref[0] = 1;
        suff[nums.size() - 1] = 1;

        for(int i = 1; i < nums.size(); i++){
            pref[i] = pref[i-1] * nums[i-1];
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            suff[i] = suff[i+1] * nums[i+1];
        }
        for(int i = 0; i < nums.size(); i++){
            output[i] = suff[i] * pref[i];
        }
        return output;
    }
};