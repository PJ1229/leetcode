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