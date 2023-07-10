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
#include <priority_queue>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
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

vector<int> solve(TreeNode *A) {
    if (!A) return {};
    queue<TreeNode *> que;
    que.push(A);
    stack<vector<int>> stk;
    while (!que.empty()) {
        int n = que.size();
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            TreeNode *node = que.front();
            que.pop();
            tmp.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        stk.push(move(tmp));
    }
    vector<int> ans;
    while (!stk.empty()) {
        vector<int> tmp(stk.top());
        stk.pop();
        for (auto &&i : tmp) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    /* code */

    return 0;
}
