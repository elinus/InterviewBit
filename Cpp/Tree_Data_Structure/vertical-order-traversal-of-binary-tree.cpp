/**
 * © 2023 Sunil Mourya. All rights reserved.
 *
 * Author: Sunil Mourya
 * Date of Creation: July 09, 2023
 * Last Modified: July 09, 2023 (Revision 1)
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

vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A) {
    vector<vector<int>> ans;
    if (!A) return ans;

    map<int, vector<int>> mp;
    int hz_dist = 0;

    queue<pair<TreeNode *, int>> que;
    que.push(make_pair(A, hz_dist));

    while (!que.empty()) {
        pair<TreeNode *, int> node_pair = que.front();
        que.pop();

        hz_dist = node_pair.second;
        TreeNode *node = node_pair.first;

        mp[hz_dist].push_back(node->val);

        if (node->left) que.push(make_pair(node->left, hz_dist - 1));
        if (node->right) que.push(make_pair(node->right, hz_dist + 1));
    }

    for (auto &&itr : mp) {
        ans.push_back(itr.second);
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    /* code */

    return 0;
}
