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

vector<int> inorderTraversal(TreeNode *A) {
    vector<int> ans;
    if (!A) return ans;
    stack<TreeNode *> stk;
    TreeNode *curr{A};
    while (curr || !stk.empty()) {
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        if (stk.empty()) break;
        curr = stk.top();
        ans.push_back(curr->val);
        stk.pop();
        curr = curr->right;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    /* code */

    return 0;
}
