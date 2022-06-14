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

// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute
// value of x. For example, A=[1, 3, -1]

// f(1, 1) = f(2, 2) = f(3, 3) = 0
// f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
// f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
// f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

int maxArr(vector<int> &A) {
  int max1 = INT_MIN, min1 = INT_MAX;
  int max2 = INT_MIN, min2 = INT_MAX;

  for (int i = 0; i < A.size(); i++) {
    max1 = max(max1, A[i] + i);
    min1 = min(min1, A[i] + i);
    max2 = max(max2, A[i] - i);
    min2 = min(min2, A[i] - i);
  }

  return max(max1 - min1, max2 - min2);
}

int main(int argc, char const *argv[]) {

  /* code */

  return 0;
}
