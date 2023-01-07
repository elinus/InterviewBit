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

int isSameTree(TreeNode *A, TreeNode *B) {
  if (!A && !B) return true;
  if (!A || !B) return false;
  return A->val == B->val && isSameTree(A->left, B->right) &&
         isSameTree(A->right, B->left);
}

int isSymmetric(TreeNode *A) { return isSameTree(A, A); }