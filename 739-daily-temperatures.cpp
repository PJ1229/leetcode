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
lets understand this logic:
repeat thru the entire array
check if stack
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> out(temperatures.size());
        out[temperatures.size() - 1] = 0;

        for(int i=0; i<temperatures.size(); i++) {
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                int j = stk.top(); 
                stk.pop();
                out[j] = i - j;
            }
            stk.push(i);
        }
        return out;
    }
};
