class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s1(nums.begin(), nums.end());
        return s1.size() != nums.size();
    }
};