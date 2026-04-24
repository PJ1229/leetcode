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
    bool isPalindrome(string s) {
        string conc = "";
        for (char c : s) {
            if ('A' <= c && c <= 'Z') {
                conc += tolower(c);
            } else if ('a' <= c && c <= 'z') {
                conc += c;
            } else if ('0' <= c && c <= '9') {
                conc += c;
            }
        }
        
        int left = 0;
        int right = conc.size() - 1;

        while (left < right) {
            if (conc[left] != conc[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};