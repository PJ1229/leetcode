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