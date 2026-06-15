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
i know this is a 2 pointer problem

height, length n

calc area with 
trying to find max of this below
min(height[left], height[right]) * (right - left + 1)

[1,2,4,3]
optimal is [2,-,3] > 

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        // init at max length
        int left = 0; //height[left] = 1
        int right = height.size() - 1; //height[right] = 7
        int ans = 0; int area = 0;
        while(left != right) {
            cout << "left: " << left << " & right: " << right << endl; 

            area = min(height[left], height[right]) * (right - left);
            ans = max(area, ans);
            if(height[left] < height[right]) left++; 
            else right--;
        }
        return ans;
    }
};
