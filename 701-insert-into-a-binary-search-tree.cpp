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
class Solution {
public:
    void addValueBST(TreeNode* root, int val) {
        if(!root) return;
        if(!root->left && val < root->val) {
            root->left = new TreeNode(val);
            return;
        }
        if(!root->right && val > root->val) {
            root->right= new TreeNode(val);
            return;
        }
        if(val < root->val) addValueBST(root->left, val);
        if(val > root->val) addValueBST(root->right, val);
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            root = new TreeNode(val);
        } else {
            addValueBST(root, val);
        }
        return root;
    }
};