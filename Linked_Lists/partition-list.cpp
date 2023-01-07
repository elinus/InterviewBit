#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *partition(ListNode *A, int B) {
  if (!A || !A->next) return A;
  ListNode part1(INT_MIN), part2(INT_MIN);
  ListNode *p1 = &part1, *p2 = &part2, *curr = A;
  while (curr) {
    if (curr->val < B) {
      p1->next = curr;
      p1 = p1->next;
    } else {
      p2->next = curr;
      p2 = p2->next;
    }
    curr = curr->next;
  }
  p2->next = nullptr;
  p1->next = part2.next;
  return part1.next;
}