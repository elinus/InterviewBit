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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x)
        : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void connect(TreeLinkNode *A) {
    if (!A) return;
    queue<TreeLinkNode *> que;
    que.push(A);

    while (!que.empty()) {
        int n = que.size();
        TreeLinkNode *prevNode{nullptr};
        for (int i = 0; i < n; i++) {
            TreeLinkNode *node = que.front();
            que.pop();
            if (prevNode != nullptr) {
                prevNode->next = node;
            }
            prevNode = node;
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
    }
}

void Solution::connect(TreeLinkNode *A) {
    TreeLinkNode *q = A;
    while (q) {
        TreeLinkNode *t = q, *newQue = NULL, *queptr;
        while (t) {
            if (t->left) {
                if (newQue == NULL) {
                    newQue = t->left;
                    queptr = t->left;
                } else {
                    queptr->next = t->left;
                    queptr = t->left;
                }
            }
            if (t->right) {
                if (newQue == NULL) {
                    newQue = t->right;
                    queptr = t->right;
                } else {
                    queptr->next = t->right;
                    queptr = t->right;
                }
            }
            t = t->next;
        }
        q = newQue;
    }
}

int main(int argc, char const *argv[]) {
    /* code */

    return 0;
}
