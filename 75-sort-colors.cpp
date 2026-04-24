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
dnf algorithm

3 pointers
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

i = 0
[1,2,0]
^^   ^
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int mid = 0; // this is elt under inspection
        int hi = nums.size() - 1;

        while(mid <= hi) {
            if(nums[mid] == 0) {
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[hi], nums[mid]);
                hi--;
            }
        }
    }
};