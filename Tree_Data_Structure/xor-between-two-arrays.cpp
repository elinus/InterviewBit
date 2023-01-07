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

struct TrieNode {
  TrieNode *left;
  TrieNode *right;
};

void insertNode(TrieNode *head, int value) {
  TrieNode *cur = head;
  for (int i = 31; i >= 0; i--) {
    int b = 1 & (value >> i);

    if (b == 0) {
      if (!cur->left) cur->left = new TrieNode();
      cur = cur->left;
    } else {
      if (!cur->right) cur->right = new TrieNode();
      cur = cur->right;
    }
  }
}

int queryXorPair(TrieNode *head, vector<int> &arr, int len) {
  int max_xor = INT_MIN;

  for (int i = 0; i < len; i++) {
    int value = arr[i];
    int cur_xor = 0;
    TrieNode *cur = head;

    for (int j = 31; j >= 0; j--) {
      int b = 1 & (value >> j);

      if (b == 0) {
        if (cur->right) {
          cur_xor += pow(2, j);
          cur = cur->right;
        } else {
          cur = cur->left;
        }
      } else {
        if (cur->left) {
          cur_xor += pow(2, j);
          cur = cur->left;
        } else {
          cur = cur->right;
        }
      }
    }

    if (cur_xor > max_xor) max_xor = cur_xor;
  }
  return max_xor;
}

int solve(vector<int> &A, vector<int> &B) {
  TrieNode *root = new TrieNode();

  for (auto &i : A) insertNode(root, i);

  int max_xor = queryXorPair(root, B, B.size());
  return max_xor;
}
