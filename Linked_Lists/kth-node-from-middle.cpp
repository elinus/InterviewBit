
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *A) {
  ListNode *prev = nullptr, *curr = A, *next = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int solve(ListNode *A, int B) {
  if (!A || !A->next)
    return -1;
  ListNode *slow = A, *fast = A, *prev = A;
  while (fast->next && fast->next->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast->next)
    slow->next = nullptr;
  else
    prev->next = nullptr;
  ListNode *tmp = reverseList(A);
  while (tmp && --B) {
    tmp = tmp->next;
  }
  return tmp ? tmp->val : -1;
}