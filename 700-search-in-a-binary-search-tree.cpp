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

#ifndef ONLINE_JUDGE
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /*
 F_n = F_(n-1) + F_(n-2)
 Fib(5) = Fib(4) + Fib(3)
 Fib(4) = Fib(3) + Fib(2)
 Fib(3) = Fib(2) + Fib(1)
 Base case:
 Fib(1) = 1
 Fib(2) = 1
 */


class Solution {
public:
    /*
    root node's value is 4
    */
    TreeNode* searchBST(TreeNode* root, int val) { // val = 2
        if(!root) { // if root doesn't exist
            return nullptr;
        }

        if(val > root->val) { // 2 > 4
            return searchBST(root->right, val);
        }
        else if(val < root->val) { // 2 < 4
            return searchBST(root->left, val); // new root is 2
        }
        else {
            return root;
        }
    }
};