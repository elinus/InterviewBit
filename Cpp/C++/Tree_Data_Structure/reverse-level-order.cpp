#include <iostream>
#include <memory>
#include <queue>
#include <stack>
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

vector<int> solve(TreeNode *A) {
  vector<int> ans;
  if (!A) return ans;

  stack<vector<int>> s;
  queue<TreeNode *> q;

  q.push(A);

  while (!q.empty()) {
    int size_ = q.size();
    vector<int> v;

    for (int i = 0; i < size_; i++) {
      auto node = q.front();
      q.pop();

      v.push_back(node->val);

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }

    s.push(v);
  }

  while (!s.empty()) {
    for (auto i = s.top().begin(); i != s.top().end(); i++) {
      ans.emplace_back(*i);
    }
    s.pop();
  }

  return ans;
}
