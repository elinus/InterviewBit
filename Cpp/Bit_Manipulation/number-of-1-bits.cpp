int numSetBits(unsigned int A) {
  unsigned int total_ones = 0;
  while (A) {
    A = A & (A - 1);
    total_ones++;
  }
  return total_ones;
}