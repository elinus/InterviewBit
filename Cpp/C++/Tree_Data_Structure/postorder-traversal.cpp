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

vector<int> postorderTraversal(TreeNode *A) {
  if (!A) return {};
  stack<TreeNode *> s;
  vector<int> ans;
  while (true) {
    while (A) {
      s.push(A);
      ans.push_back(A->val);
      A = A->right;
    }
    if (s.empty()) break;
    A = s.top();
    s.pop();
    A = A->left;
  }
  reverse(begin(ans), end(ans));
  return ans;
}