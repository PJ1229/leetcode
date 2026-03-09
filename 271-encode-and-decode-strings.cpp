/*
used help but this one is pretty simple. 
just store the divider btw words and the length of the words in the encoder
*/

class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for(auto i : strs) {
            output += to_string(i.length());
            output += "#";
            output += i;
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        int i = 0;
        while(i < s.length()) {
            int pos = s.find("#", i);
            int length = stoi(s.substr(i, pos - i));
            i = pos + 1;
            output.push_back(s.substr(i, length));
            i += length;
        }
        return output;
    }
};