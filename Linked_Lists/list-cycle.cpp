#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *A) {
  if (!A || !A->next) return nullptr;
  ListNode *slow = A, *fast = A;
  bool has_cycle = false;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      has_cycle = true;
      break;
    }
  }
  if (has_cycle) {
    slow = A;
    while (true) {
      if (slow == fast) return slow;
      slow = slow->next;
      fast = fast->next;
    }
  }
  return nullptr;
}