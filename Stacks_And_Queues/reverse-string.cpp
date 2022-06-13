#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string A) {
  stack<char> s;
  for (int i = 0; i < A.length(); ++i) {
    s.push(A[i]);
  }
  string ans;
  while (!s.empty()) {
    ans += s.top();
    s.pop();
  }
  return ans;
}
