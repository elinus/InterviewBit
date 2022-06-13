#include <stack>

using namespace std;

stack<int> s, ms;

// MinStack() {
//   s = stack<int>();
//   ms = stack<int>();
// }

void push(int x) {
  s.push(x);
  if (ms.empty() || x <= ms.top()) {
    ms.push(x);
  }
}

void pop() {
  if (s.empty())
    return;
  int val = s.top();
  s.pop();
  if (val == ms.top())
    ms.pop();
}

int top() { return s.empty() ? -1 : s.top(); }

int getMin() { return ms.empty() ? -1 : ms.top(); }
