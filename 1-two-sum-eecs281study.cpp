/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        /*
        hashmap: (hash)
        key value
        lemon : "a sour fruit"
        phone : "mobile device"

        O(1)
        */
        for(int i=0; i<nums.size(); i++) { // 0 > 1
            if(hash.contains(nums[i]) && i != hash[nums[i]]) { // if hash contains 7
                return {i, hash[nums[i]]}; // 0, 1
            }
            int comp = target - nums[i]; // 9 - 2 = 7
            hash[comp] = i; // 7 : 0
        }
        return {-1, -1};
    }
};