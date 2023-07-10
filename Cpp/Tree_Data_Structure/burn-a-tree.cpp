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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& adj,
                int parent) {
    if (!root) return;
    if (parent != -1) {
        adj[parent].push_back(root->val);
        adj[root->val].push_back(parent);
    }
    buildGraph(root->left, adj, root->val);
    buildGraph(root->right, adj, root->val);
}

int solve(TreeNode* A, int B) {
    unordered_map<int, vector<int>> adj;
    buildGraph(A, adj, -1);

    unordered_map<int, int> visited;

    queue<pair<int, int>> que;
    que.push({B, 0});
    int ans{0};
    while (!que.empty()) {
        int node = que.front().first;
        int level = que.front().second;
        ans = max(level, ans);
        que.pop();
        visited[node] = 1;
        for (auto&& it : adj[node]) {
            if (!visited[it]) {
                que.push(make_pair(it, level + 1));
                visited[it] = 1;
            }
        }
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}