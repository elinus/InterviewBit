#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
  bool negative = false;
  if (x < 0) {
    negative = true;
    x = -x;
  }
  long long int rev = 0;
  while (x) {
    rev = 10 * rev + x % 10;
    x /= 10;
  }
  if (negative && -rev < INT_MIN)
    return 0;
  else if (rev > INT_MAX)
    return 0;
  else
    return negative ? -rev : rev;
}
