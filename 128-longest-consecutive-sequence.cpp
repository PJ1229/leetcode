/*
needed help, initially used bucket sort
didn't know sets have O(1) look up

sol:
- run through the set 
- if doesnt contain num-1, start checking num+1
- check til hit end
- return max length

O(n) storage + time
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int max_length = 0;

        for (int num : s) {
            if (s.find(num - 1) == s.end()) {   // start of sequence
                int current = num;
                int length = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }

                max_length = max(max_length, length);
            }
        }

        return max_length;
    }
};

/*
if (nums.empty()) return 0;

int c_max = *max_element(nums.begin(), nums.end());
int c_min = *min_element(nums.begin(), nums.end());

int offset = -c_min;
int dist = c_max - c_min + 1;

vector<bool> bucket(dist, false);

for (int x : nums) {
    bucket[x + offset] = true;
}

int length = 0;
int max_length = 0;

for (int i = 0; i < dist; i++) {
    if (bucket[i]) {
        length++;
        max_length = max(max_length, length);
    } else {
        length = 0;
    }
}

return max_length;
*/