#include <iostream>
#include <stack>
#include <string>

using namespace std;

int isValid(string A) {
  stack<char> st;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] == '[' || A[i] == '{' || A[i] == '(') {
      st.push(A[i]);
    } else if (A[i] == ']' || A[i] == '}' || A[i] == ')') {
      if (st.empty()) return 0;
      if (A[i] == ']' && st.top() != '[') return 0;
      if (A[i] == '}' && st.top() != '{') return 0;
      if (A[i] == ')' && st.top() != '(') return 0;
      st.pop();
    }
  }
  return st.empty() ? 1 : 0;
}