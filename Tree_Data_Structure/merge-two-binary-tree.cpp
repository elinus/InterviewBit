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

TreeNode *solve(TreeNode *A, TreeNode *B) {
  if (!A)
    return B;
  if (!B)
    return A;
  A->val += B->val;
  if (B->left)
    A->left = solve(A->left, B->left);
  if (B->right)
    A->right = solve(A->right, B->right);
  return A;
}