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

void preorder(TreeNode *root, int target, vector<int> &tmp,
              vector<vector<int>> &ans) {
  if (!root) return;
  tmp.push_back(root->val);
  target -= root->val;
  if (!root->left && !root->right && target == 0) {
    ans.push_back(tmp);
  }
  preorder(root->left, target, tmp, ans);
  preorder(root->right, target, tmp, ans);
  tmp.pop_back();
}

vector<vector<int>> pathSum(TreeNode *A, int B) {
  vector<vector<int>> ans;
  if (!A) return ans;
  vector<int> tmp;
  preorder(A, B, tmp, ans);
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */

  return 0;
}
