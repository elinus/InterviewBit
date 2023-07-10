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

void preorder(TreeNode *A, map<int, vector<int>> &ht, int key) {
    if (!A) return;
    ht[key].push_back(A->val);
    preorder(A->left, ht, key + 1);
    preorder(A->right, ht, key);
}

vector<int> solve(TreeNode *A) {
    if (!A) return {};
    map<int, vector<int>> ht;
    vector<int> diag_trav;
    preorder(A, ht, 0);
    for (auto &&elem_vec : ht) {
        for (auto &&elem_i : elem_vec.second) {
            diag_trav.push_back(elem_i);
        }
    }

    return diag_trav;
}

int main(int argc, char const *argv[]) {
    /* code */

    return 0;
}
