#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
Example:
Prefixes: ["cat", "bat", "rat"]
Sentence: ["the", "cattle", "was", "rattled", "by", "the", "battery"]
Output: ["the", "cat", "was", "rat", "by", "the", "bat"]
*/

bool check_prefix(const string& pre, const string& word) {
    if (pre.size() > word.size()) return false;

    for (int i = 0; i < pre.size(); i++) {
        if (pre[i] != word[i]) {
            return false;
        }
    }
    return true;
}

vector<string> replace_words(
    const vector<string>& prefixes,
    const vector<string>& sentence
) {
    vector<string> out;

    for (const auto& word : sentence) {
        string replacement = word;

        for (const auto& pre : prefixes) {
            if (check_prefix(pre, word)) {
                replacement = pre;
                break;
            }
        }

        out.push_back(replacement);
    }

    return out;
}

// Helper to print vectors
void print_vector(const vector<string>& vec) {
    cout << "[ ";
    for (const auto& s : vec) {
        cout << "\"" << s << "\" ";
    }
    cout << "]" << endl;
}

int main() {
    vector<string> prefixes1 = {"cat", "bat", "rat"};
    vector<string> sentence1 = {"the", "cattle", "was", "rattled", "by", "the", "battery"};

    cout << "test case:" << endl;
    vector<string> result1 = replace_words(prefixes1, sentence1);
    print_vector(result1);
    cout << endl;
    return 0;
}