#include <bits/stdc++.h>

using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
  int distance = 0;
  int n = A.size();
  for (int i = 0; i < n - 1; i++) {
    int a_dist = abs(A[i + 1] - A[i]);
    int b_dist = abs(B[i + 1] - B[i]);
    distance += (a_dist > b_dist) ? a_dist : b_dist;
  }
  return distance;
}
