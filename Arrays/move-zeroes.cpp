#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector<int> &A) {
  int n = A.size();
  if (n <= 1) return A;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i]) swap(A[i], A[j++]);
  }
  return A;
}