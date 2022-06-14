#include <iostream>
#include <set>
#include <vector>

using namespace std;

int solve(vector<int> &A) {
  int n = A.size();
  int dp[n];
  dp[n - 1] = A[n - 1];
  for (int i = n - 2; i >= 0; i--)
    dp[i] = max(dp[i + 1], A[i]);
  int ans = 0;
  set<int> s;
  s.insert(A[0]);
  for (int i = 1; i < n - 1; i++) {
    auto it = s.lower_bound(A[i]);
    if (it == s.begin() || A[i] >= dp[i + 1]) {
      s.insert(A[i]);
      continue;
    }
    it--;
    int res = A[i] + (*it) + dp[i + 1];
    ans = max(ans, res);
    s.insert(A[i]);
  }
  return ans;
}
