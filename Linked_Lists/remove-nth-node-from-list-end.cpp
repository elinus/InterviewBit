#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeNthFromEnd(ListNode *A, int B) {
  if (!A)
    return A;
  ListNode *slow = A, *fast = A;
  while (fast && B--) {
    fast = fast->next;
  }
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next;
  }
  if (!fast) {
    A = A->next;
  } else {
    slow->next = slow->next->next;
  }
  return A;
}