class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> cs;
        map<char, int> ct;

        for(auto i : s) {
            cs[i]++;
        }

        for(auto i : t) {
            ct[i]++;
        }

        return cs == ct;
    }
};