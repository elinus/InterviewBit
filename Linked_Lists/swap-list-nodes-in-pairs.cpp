#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *swapPairs(ListNode *A) {
  if (!A || !A->next)
    return A;
  ListNode *nextp = swapPairs(A->next->next);
  ListNode *second = A->next;
  A->next->next = A;
  A->next = nextp;
  return second;
}