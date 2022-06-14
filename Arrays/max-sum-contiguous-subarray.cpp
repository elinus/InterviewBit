#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(const vector<int> &A) {
  int max_so_far = A[0], max_end_here = A[0], i;
  for (i = 1; i < A.size(); ++i) {
    max_end_here = std::max(A[i], max_end_here + A[i]);
    max_so_far = std::max(max_end_here, max_so_far);
  }
  return max_so_far;
}