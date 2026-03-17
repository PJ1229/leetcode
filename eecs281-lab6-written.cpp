#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void two_pair_sums(const vector<int>& input_vec, ostream& out) {
    unordered_map<int, pair<int, int>> seen;

    for (size_t i = 0; i < input_vec.size(); i++) {
        for (size_t j = i + 1; j < input_vec.size(); j++) {
            int sum = input_vec[i] + input_vec[j];

            if (seen.find(sum) != seen.end()) {
                auto prev = seen[sum];
                out << "(" << prev.first << " , " << prev.second << ")";
                out << " and ";
                out << "(" << input_vec[i] << " , " << input_vec[j] << ")";
                out << '\n';
            } else {
                seen[sum] = {input_vec[i], input_vec[j]};
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