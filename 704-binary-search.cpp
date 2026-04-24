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
basically right but as i thought before you need an parameter to keep track
*/

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;

        int med = left + (right - left) / 2;

        if (nums[med] == target) return med;
        if (nums[med] > target) {
            return binarySearch(nums, target, left, med - 1);
        } else {
            return binarySearch(nums, target, med + 1, right);
        }
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};