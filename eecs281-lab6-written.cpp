#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void two_pair_sums(const vector<int>& input_vec, ostream& out) {
    unordered_map<int, vector<pair<int, int>>> hash;

    for (size_t i = 0; i < input_vec.size(); i++) {
        for (size_t j = i + 1; j < input_vec.size(); j++) {
            int val1 = input_vec[i];
            int val2 = input_vec[j];
            hash[val1 + val2].push_back({val1, val2});
        }
    }

    for (const auto& entry : hash) {
        const vector<pair<int, int>>& pairs = entry.second;
        if (pairs.size() > 1) {
            for (size_t i = 0; i < pairs.size(); i++) {
                for (size_t j = i + 1; j < pairs.size(); j++) {
                    out << "(" << pairs[i].first << " , " << pairs[i].second << ")";
                    out << " and ";
                    out << "(" << pairs[j].first << " , " << pairs[j].second << ")";
                    out << '\n';
                }
            }
        }
    }
}

void run_test(const vector<int>& input, const string& test_name) {
    ostringstream out;
    two_pair_sums(input, out);

    cout << "==== " << test_name << " ====\n";
    cout << "Input: ";
    cout << "{ ";
    for (int x : input) {
        cout << x << " ";
    }
    cout << "}\n";

    cout << "Output:\n";
    cout << out.str() << "\n\n";
}

int main() {

    run_test({3 , 4 , 7 , 1 , 2 , 8}, "Test 1: Mixed values");

    return 0;
}