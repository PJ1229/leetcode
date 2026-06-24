#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// push to the heap everytime u add i dont think this is max time complexity tho what if we just had a variable

class MinStack {
private:
    vector<int> minStack;
    vector<int> stack;
public:
    MinStack() {
        minStack.push_back(INT_MAX);
    }
    
    void push(int value) {
        stack.push_back(value);
        if(value <= minStack.back()) {
            minStack.push_back(value);
        }
    }
    
    void pop() {
        if(minStack.back() == stack.back()) {
            minStack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() { 
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
