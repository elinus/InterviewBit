#include <iostream>
#include <set>
#include <vector>

using namespace std;

int solve(vector<int> &A) {
  int prev = INT_MIN;
  int ans = 0;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] > prev) {
      ans++;
      prev = A[i];
    }
  }
  return ans;
}