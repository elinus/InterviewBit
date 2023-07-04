#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <deque>
#include <forward_list>
#include <iostream>
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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode *root, int target, int &ans) {
  if (!root) return;
  target -= root->val;
  if (!root->left && !root->right && target == 0) {
    ans = 1;
    return;
  }
  preorder(root->left, target, ans);
  preorder(root->right, target, ans);
}

int hasPathSum(TreeNode *A, int B) {
  if (!A) return 0;
  int ans = 0;
  preorder(A, B, ans);
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */

  return 0;
}
