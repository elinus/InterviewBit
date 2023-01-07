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

vector<int> solve(vector<int> &A) {
  int n = A.size();
  int min_elem = INT_MAX;
  int min_index = -1;
  for (int i = 0; i < n; i++) {
    A[i] = A[i] * A[i];
    if (A[i] < min_elem) {
      min_elem = A[i];
      min_index = i;
    }
  }
  vector<int> ans(A.size(), 0);
  int k = 0;
  ans[k++] = A[min_index];
  int pre = min_index - 1, post = min_index + 1;
  while (pre >= 0 && post < n) {
    if (A[pre] < A[post]) {
      ans[k++] = A[pre--];
    } else {
      ans[k++] = A[post++];
    }
  }
  while (pre >= 0) {
    ans[k++] = A[pre--];
  }
  while (post < n) {
    ans[k++] = A[post++];
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */

  return 0;
}
