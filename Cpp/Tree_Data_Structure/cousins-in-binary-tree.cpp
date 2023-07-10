/**
 * © 2023 Sunil Mourya. All rights reserved.
 *
 * Author: Sunil Mourya
 * Date of Creation: July 10, 2023
 * Last Modified: July 10, 2023 (Revision 1)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <forward_list>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// vector<int> solve(TreeNode *A, int B) {
//     if (!A) return {};
//     queue<pair<TreeNode *, TreeNode *>> que;  // Pair_of(parent, child)
//     que.push(make_pair(nullptr, A));
//     vector<int> ans;
//     bool found{false};
//     TreeNode *found_parent{nullptr};
//     while (!que.empty()) {
//         int n = que.size();
//         vector<pair<TreeNode *, TreeNode *>> tmp;
//         for (int i = 0; i < n; i++) {
//             pair<TreeNode *, TreeNode *> node = que.front();
//             que.pop();

//             tmp.push_back(node);

//             TreeNode *parent = node.first;
//             TreeNode *child = node.second;

//             if (child->val == B) {
//                 found = true;
//                 found_parent = parent;
//             }

//             if (child->left) que.push(make_pair(child, child->left));
//             if (child->right) que.push(make_pair(child, child->right));
//         }
//         if (found) {
//             for (auto &&elem : tmp) {
//                 if (elem.first != found_parent)
//                 ans.push_back(elem.second->val);
//             }

//             break;
//         }
//     }
//     return ans;
// }

vector<int> solve(TreeNode *A, int B) {
    queue<TreeNode *> que;
    que.push(A);
    vector<int> ans;
    while (!que.empty()) {
        int n = que.size();
        int found{false};
        for (int i = 0; i < n; i++) {
            TreeNode *node = que.front();
            que.pop();
            if (node->left && node->left->val == B)
                found = true;
            else if (node->right && node->right->val == B)
                found = true;
            else {
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        if (found) {
            while (!que.empty()) {
                ans.push_back(que.front()->val);
                que.pop();
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> res = solve(root, 7);

    for (auto &&i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
