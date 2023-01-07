#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
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

ListNode *reverseBetween(ListNode *A, int B, int C) {
  if (!A || !A->next) return A;
  ListNode dummy(INT_MIN);
  ListNode *pre = nullptr, *lt = &dummy, *nex = nullptr, *rt = nullptr;
  lt->next = A;
  int l = B;
  while (lt && l--) {
    pre = lt;
    lt = lt->next;
  }
  rt = lt;
  int r = C - B;
  while (rt && r--) {
    rt = rt->next;
  }
  nex = rt->next;
  rt->next = nullptr;
  ListNode *rev = reverseList(lt);
  pre->next = rev;
  lt->next = nex;
  return dummy.next;
}
