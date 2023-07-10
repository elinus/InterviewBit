/**
 * © 2023 Sunil Mourya. All rights reserved.
 *
 * Author: Sunil Mourya
 * Date of Creation: July 09, 2023
 * Last Modified: July 09, 2023 (Revision 1)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
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

long Solution::coveredNodes(TreeNode *A) {
    if (!A) return {};
    long ans{0}, uncover_sum{0}, uncover_sum{0};
    queue<TreeNode *> qe;
    qe.push(A);
    while (!qe.empty()) {
        int n = qe.size();
        for (int i = 0; i < n; i++) {
            TreeNode *node = qe.front();
            qe.pop();
            if (i == 0 || i == (n - 1)) {
                uncover_sum += node->val;
            } else {
                cover_sum += node->val;
            }
            if (node->left) qe.push(node->left);
            if (node->right) qe.push(node->right);
        }
    }
    return abs(uncover_sum - uncover_sum);
}

int main(int argc, char const *argv[]) {
    /* code */

    return 0;
}
