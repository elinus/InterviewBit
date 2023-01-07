#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *rotateRight(ListNode *A, int B) {
  if (!A || !A->next) return A;
  int len = 0;
  ListNode *curr = A, *last = nullptr;
  while (curr) {
    len++;
    last = curr;
    curr = curr->next;
  }
  B = len - (B % len);
  last->next = A;
  curr = A;
  while (curr && B--) {
    last = curr;
    curr = curr->next;
  }
  last->next = nullptr;
  return curr;
}
