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
map
char count
char[26]

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> hash;
        for(auto i : strs) {
            array<int, 26> id{};
            for(auto j : i) {
                id[j - 'a']++;
            }
            hash[id].push_back(i);
        }
        vector<vector<string>> output;
        for(auto i : hash) {
            output.push_back(i.second);
        }
        return output;
    }
};

#if 0
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, int> hash; // -1 for using map (unordered_map can't key arrays)
        vector<vector<string>> out;
        for(auto i : strs) {
            array<int, 26> key = {};
            for(auto c : i) {
                key[c - 'a']++;
            }
            if(hash.contains(key)) {
                out[hash[key]].push_back(i);
            } else {
                hash[key] = out.size();
                out.push_back({i});
            }
        }
        return out;
    }
};
#endif