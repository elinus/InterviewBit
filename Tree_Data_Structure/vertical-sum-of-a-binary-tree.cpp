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

void inorder(TreeNode *root, int key, map<int, int> &ht) {
  if (!root) return;
  ht[key] += root->val;
  inorder(root->left, key - 1, ht);
  inorder(root->right, key + 1, ht);
}

vector<int> verticalSum(TreeNode *A) {
  vector<int> ans;
  if (!A) return ans;
  map<int, int> ht;
  inorder(A, 0, ht);
  for (auto it = begin(ht); it != end(ht); ++it) {
    ans.push_back(it->second);
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */

  return 0;
}
