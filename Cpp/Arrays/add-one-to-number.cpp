#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &A) {
  int n = A.size();
  if (!n) return {};
  reverse(begin(A), end(A));
  A[0] += 1;
  int carry = A[0] / 10;
  A[0] %= 10;

  for (int i = 1; i < n; i++) {
    A[i] = A[i] + carry;
    carry = A[i] / 10;
    A[i] %= 10;
  }
  if (carry) A.push_back(1);
  while (!A.back()) {
    A.pop_back();
  }

  reverse(begin(A), end(A));
  return A;
}