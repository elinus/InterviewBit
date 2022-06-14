#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &A) {
  int max = INT_MIN, min = INT_MAX;
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] > max)
      max = A[i];
    if (A[i] < min)
      min = A[i];
  }
  return max + min;
}