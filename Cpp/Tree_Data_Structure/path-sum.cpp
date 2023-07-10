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

void preorder(TreeNode *root, int sum, bool &ans) {
    if (!root) return;
    sum -= root->val;
    if (!root->left && !root->right && sum == 0) {
        ans = true;
        return;
    }
    preorder(root->left, sum, ans);
    preorder(root->right, sum, ans);
}

int hasPathSum(TreeNode *A, int B) {
    bool ans{false};
    preorder(A, B, ans);
    return ans;
}

int main(int argc, char const *argv[]) {
    /* code */

    return 0;
}
