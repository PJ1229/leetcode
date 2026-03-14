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