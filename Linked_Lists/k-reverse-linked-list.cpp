#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *A, int B) {
  ListNode *curr = A;
  for (int i = 0; i < B; ++i) {
    if (!curr)
      return A;
    curr = curr->next;
  }
  ListNode *prev = nullptr, *next = nullptr;
  curr = A;
  for (int i = 0; i < B; ++i) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  A->next = reverseList(next, B);
  return prev;
}