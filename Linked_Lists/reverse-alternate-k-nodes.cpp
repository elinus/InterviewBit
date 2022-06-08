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

ListNode *solve(ListNode *A, int B) {
  if (!A || !A->next)
    return A;
  ListNode *prev = nullptr, *curr = A, *start = nullptr, *end = nullptr;
  ListNode dummy(INT_MIN);
  int re_flag = 1;
  while (curr) {
    start = curr;
    int count = B;
    while (curr && count--) {
      prev = curr;
      curr = curr->next;
    }

    if (re_flag) {
      prev->next = nullptr;
      ListNode *tmp = reverseList(start);
      if (!dummy.next)
        dummy.next = tmp;
      if (end)
        end->next = tmp;
      start->next = curr;
    }
    re_flag = 1 - re_flag;
    end = prev;
  }
  return dummy.next;
}