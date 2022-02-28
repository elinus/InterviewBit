int numSetBits(unsigned int A) {
  unsigned int n = A;
  int ans = 0;
  while (n) {
    if (n & 1)
      ans++;
    n >>= 1;
  }
  return ans;
}