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

vector<int> addArrays(vector<int> &A, vector<int> &B) {
  if (A.empty()) return B;
  if (B.empty()) return A;
  vector<int> ans;
  int carry = 0;
  int i = A.size() - 1, j = B.size() - 1;

  while (i >= 0 && j >= 0) {
    int sum = A[i] + B[j] + carry;
    if (sum > 9) {
      carry = 1;
      ans.push_back(sum % 10);
    } else {
      carry = 0;
      ans.push_back(sum);
    }
    i--;
    j--;
  }
  while (i >= 0) {
    int sum = A[i] + carry;
    if (sum > 9) {
      carry = 1;
      ans.push_back(sum % 10);
    } else {
      carry = 0;
      ans.push_back(sum);
    }
    i--;
  }
  while (j >= 0) {
    int sum = B[j] + carry;
    if (sum > 9) {
      carry = 1;
      ans.push_back(sum % 10);
    } else {
      carry = 0;
      ans.push_back(sum);
    }
    j--;
  }
  if (carry) {
    ans.push_back(1);
  }
  reverse(begin(ans), end(ans));
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */

  return 0;
}
