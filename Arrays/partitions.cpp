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

int solve(int A, vector<int> &B) {
  int s = 0;
  vector<int> cnt(A, 0);

  // Calculating the sum of the array
  // and storing it in variable s
  for (int i = 0; i < A; i++) {
    s += B[i];
  }

  // Checking s is divisible by 3 or not
  if (s % 3 != 0)
    return 0;

  // Calculating the sum of each part
  s /= 3;

  int ss = 0;

  // If the sum of elements from i-th to n-th
  // equals to sum of part putting 1 in cnt
  // array otherwise 0.
  for (int i = A - 1; i >= 0; i--) {
    ss += B[i];
    if (ss == s)
      cnt[i] = 1;
  }

  // Calculating the cumulative sum
  // of the array cnt from the last index.
  for (int i = A - 2; i >= 0; i--)
    cnt[i] += cnt[i + 1];

  int ans = 0;
  ss = 0;

  // Calculating answer using original
  // and cnt array.
  for (int i = 0; i + 2 < A; i++) {
    ss += B[i];
    if (ss == s)
      ans += cnt[i + 2];
  }
  return ans;
}

int main(int argc, char const *argv[]) {

  /* code */

  return 0;
}
