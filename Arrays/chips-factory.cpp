#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> solve(vector<int> &A) {
  int k = 0;
  for (int i = 0; i < A.size(); i++) {
    if (A[i]) {
      A[k++] = A[i];
    }
  }
  for (int i = k; i < A.size(); i++) {
    A[i] = 0;
  }

  return A;
}