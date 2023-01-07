#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int A) {
  vector<string> ans(A, "");
  for (int i = 0; i < A; i++) {
    int n = i + 1;
    if (n % 3 == 0 && n % 5 == 0) {
      ans[i] = "FizzBuzz";
    } else if (n % 3 == 0) {
      ans[i] = "Fizz";
    } else if (n % 5 == 0) {
      ans[i] = "Buzz";
    } else {
      ans[i] = to_string(n);
    }
  }
  return ans;
}
