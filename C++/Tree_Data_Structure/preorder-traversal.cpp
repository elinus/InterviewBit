#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *A) {
  if (!A) return {};
  stack<TreeNode *> s;
  vector<int> ans;
  while (true) {
    while (A) {
      s.push(A);
      ans.push_back(A->val);
      A = A->left;
    }
    if (s.empty()) break;
    A = s.top();
    s.pop();
    A = A->right;
  }
  return ans;
}