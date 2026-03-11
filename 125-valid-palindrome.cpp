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