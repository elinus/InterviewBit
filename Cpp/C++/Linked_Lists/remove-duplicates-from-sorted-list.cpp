#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteDuplicates(ListNode *A) {
  if (!A || !A->next) return A;
  ListNode dummy(INT_MIN);
  ListNode *tail = &dummy, *curr = A;
  while (curr) {
    if (curr->val != tail->val) {
      tail->next = curr;
      tail = tail->next;
    }
    curr = curr->next;
  }
  tail->next = nullptr;
  return dummy.next;
}
