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

void preorder(TreeNode *root, int sum, vector<int> &tmp,
              vector<vector<int>> &ans) {
    if (!root) return;
    tmp.push_back(root->val);
    sum -= root->val;
    if (!root->left && !root->right && sum == 0) {
        ans.push_back(tmp);
        tmp.pop_back();
        return;
    }
    preorder(root->left, sum, tmp, ans);
    preorder(root->right, sum, tmp, ans);
    tmp.pop_back();
}

vector<vector<int>> pathSum(TreeNode *A, int B) {
    vector<vector<int>> ans;
    vector<int> tmp;
    preorder(A, B, tmp, ans);
    return ans;
}

int main(int argc, char const *argv[]) {
    /* code */

    return 0;
}
