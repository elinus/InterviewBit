#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *solve(ListNode *A) {
  if (!A || !A->next)
    return A;
  ListNode list0(INT_MIN), list1(INT_MIN);
  ListNode *p0 = &list0, *p1 = &list1, *curr = A;
  while (curr) {
    if (curr->val) {
      p1->next = curr;
      p1 = p1->next;
    } else {
      p0->next = curr;
      p0 = p0->next;
    }
    curr = curr->next;
  }
  p0->next = list1.next;
  p1->next = nullptr;
  return list0.next;
}