#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int isPalindrome(string A) {
  transform(A.begin(), A.end(), A.begin(), ::tolower);
  // cout << "A: " << A << endl;
  int i = 0, j = A.length() - 1;
  while (i < j) {
    if (!isalnum(A[i]))
      i++;
    if (!isalnum(A[j]))
      j--;
    if (isalnum(A[i]) && isalnum(A[j]) && A[i] == A[j]) {
      i++;
      j--;
    }
    if (isalnum(A[i]) && isalnum(A[j]) && A[i] != A[j])
      return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  string s1{"A man, a plan, a canal: Panama"};
  string s2{"race a car"};
  cout << isPalindrome(s1) << endl;
  cout << isPalindrome(s2) << endl;
  return 0;
}
