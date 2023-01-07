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

vector<int> solve(TreeNode *A) {
  if (!A) return {};

  vector<int> ans;

  queue<TreeNode *> q;
  q.push(A);

  while (!q.empty()) {
    int qsize = q.size();
    for (int i = 0; i < qsize; i++) {
      auto node = q.front();
      q.pop();
      if (i == qsize - 1) {
        ans.push_back(node->val);
      }
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */

  return 0;
}
