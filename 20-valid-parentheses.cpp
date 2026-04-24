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
    char checkParentheses(char p) {
        if(p == '(') return ')';
        if(p == '[') return ']';
        if(p == '{') return '}';
        return 'x';
    }

    bool isValid(string s) {
        stack<char> c;
        for(char i : s) {
            if(!c.empty() && checkParentheses(c.top()) == i) {
                c.pop();
            } else {
                c.push(i);
            }
        }
        return c.empty();
    }
};