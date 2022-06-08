#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteDuplicates(ListNode *A) {
  if (!A || !A->next)
    return A;
  ListNode dummy(INT_MIN);
  ListNode *curr = A, *next = nullptr, *end = &dummy;
  while (curr && curr->next) {
    next = curr->next;
    if (curr->val != next->val) {
      end->next = curr;
      end = end->next;
    } else if (curr->val == next->val) {
      while (curr && next && curr->val == next->val)
        next = next->next;
    }
    curr = next;
  }
  end->next = curr;
  return dummy.next;
}